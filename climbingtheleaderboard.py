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
#
def climbingLeaderboard(ranked, player):
    # don't need duplicates
    ranked = list(set(ranked))
    ranked.sort()
    
    playerrank = []
    lastidx = 0
    n = len(ranked) + 1
    found = False
    for p in player:
        for i in range(lastidx, len(ranked)):
            r = ranked[i]
            if p < r:
                playerrank.append(n - i)
                lastidx = i
                found = True
                break
        if found is False:
            playerrank.append(1)
            lastidx = len(ranked)
        found = False

    return playerrank
