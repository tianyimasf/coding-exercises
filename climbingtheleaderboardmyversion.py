#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'climbingLeaderboard' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY ranked
#  2. INTEGER_ARRAY player
#
# Original link: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true
# My version: I redesigned the question so that the question becomes:
# If the players were to be added to the leaderboard all at the same time, what would be their resulting rank?
#
def createPlayerHashmap(player):
    hm = {}
    for i, p in enumerate(player):
        if p not in hm.keys():
            hm[p] = [i]
        else:
            hm[p].append(i)
    return hm

def createRankedHashmap(ranked):
    hm = {}
    for i, p in enumerate(ranked):
        hm[p] = i+1
    return hm

def climbingLeaderboard(ranked, player):
    # don't need duplicates
    ranked = list(set(ranked))
    ranked.sort(reverse=True)
    # store the original order of player
    player_hm = createPlayerHashmap(player)
    # create variable to store result -- players' ranks
    playerrank = [0] * len(player)
    # sort player in descending order and remove duplicates
    # so that for every player[i], player[j] pair where i < j,
    # we only need to search rank[k] where k < player[i].rank
    player = list(set(player))
    player.sort(reverse=True)
    
    # step 1: insert player into ranked
    playerranked = []
    prevrank = 0
    for p in player:
        prevranked = ranked[prevrank]
        currrank = prevrank
        # prevrank = the rank of the last player > p.rank
        # covers the case when p.rank > prevrank
        if p > prevranked:
            playerranked.append(p)
            continue
        if prevrank is len(ranked)-1:
            playerranked.append(p)
        for i in range(prevrank+1, len(ranked)):
            currranked = ranked[i]
            if playerranked[-1] is not prevranked:
                playerranked.append(prevranked)
            # covers the cases when prevrank < p.rank > ranked[n] 
            if p < prevranked and p > currranked:
                currrank = i
                playerranked.append(p)
                break
            # covers the case when p.rank < ranked[n]
            elif p < currranked and i is len(ranked)-1: 
                playerranked.append(currranked)
                playerranked.append(p)
                currrank = len(ranked)
            elif p is prevranked:
                currrank = i-1
                break
            elif p is currranked:
                currrank = i
                break
            elif currranked not in playerranked:
                playerranked.append(currranked)
            # inner loop ranked
            prevranked = currranked
        # outer loop p.rank
        prevrank = currrank
    # covers the case when player[m].rank > ranked[n]
    if currrank is not len(ranked) and currrank is not len(ranked)-1:
        playerranked += ranked[currrank:len(ranked)-1]
    # create hashmap for better rank lookup
    playerranked_hm = createRankedHashmap(playerranked)
    print(player)
    print(playerranked)
    # fill in the ranks
    for p in player_hm:
        idxes = player_hm[p]
        rank = playerranked_hm[p]
        for idx in idxes:
            playerrank[idx] = rank
    return playerrank

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ranked_count = int(input().strip())

    ranked = list(map(int, input().rstrip().split()))

    player_count = int(input().strip())

    player = list(map(int, input().rstrip().split()))

    result = climbingLeaderboard(ranked, player)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
