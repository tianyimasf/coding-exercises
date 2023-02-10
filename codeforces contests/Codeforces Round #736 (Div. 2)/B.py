import numpy as np

def countConsecutiveBlocks(n, pawns):
	blocks = [[0, 0, 0]]
	count = 0
	ifCount = False
	start = -1
	ifFirst = True
	for i in range(0, n):
		if ifCount == False and pawns[i] == '1':
			ifCount = True
			count += 1
			start = i		
		elif ifCount == True and (pawns[i] == '0' or (pawns[i] == '1' and i == n-1)):
			if pawns[i] == '1' and i == n-1:
				count += 1
			if ifFirst == True:
				del blocks[-1]
				ifFirst = False
			blocks.append([start, i, count])
			ifCount = False
			count = 0
			start = -1
		elif ifCount == True and pawns[i] == '1':
			count+=1

	return blocks


def solve(n, enemy, gregor):
	enemy_blocks = countConsecutiveBlocks(n, enemy)
	gregor_blocks = countConsecutiveBlocks(n, gregor)
	sol = 0
	for eb, gb in zip(enemy_blocks, gregor_blocks):
		if not (eb[2] == 1 and gb[2] == 1):
			block_num = gb[2]
			sol += block_num
	return sol


test_cases = int(input())

for i in range(0, test_cases):
	n = int(input())
	enemy = input()
	gregor = input()
	print(solve(n, enemy, gregor))