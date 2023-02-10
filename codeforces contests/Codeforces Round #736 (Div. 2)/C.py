import numpy as np

def solve(m, matrix):
	alice_score, bob_score = [[0 for i in range(0, m)], [0 for i in range(0, m)]], [[0 for i in range(0, m)], [0 for i in range(0, m)]]

	# initialize alice's dynamic programming matrix
	alice = [[0, 0]]
	alice_score[0][0] = matrix[0][0]
	alice_score[1][0] = matrix[0][0] + matrix[1][0]

	# calculate alice's path
	for i in range(0, m-1):
		alice_score[0][i+1] = matrix[0][i+1] + alice_score[0][i]
	for i in range(0, m-1):
		alice_score[1][i+1] = min(alice_score[0][i+1], alice_score[1][i]) + matrix[1][i+1]
		idx = np.argmin([alice_score[0][i+1], alice_score[1][i]])
		if idx == 0:
			alice = i+1

	# update coins in alice's path to be 0
	for i in range(0, alice+1):
		matrix[0][i] = 0
		if i + alice < m:
			matrix[1][i+alice] = 0

	# initialize bob's dynamic programming matrix
	bob_score[1][0] = matrix[1][0]

	# calculate bob's path
	for i in range(0, m-1):
		bob_score[0][i+1] = matrix[0][i+1] + bob_score[0][i]
	for i in range(0, m-1):
		bob_score[1][i+1] = max(bob_score[0][i+1], bob_score[1][i]) + matrix[1][i+1]

	return bob_score[1][m-1]


test_cases = int(input())

for i in range(0, test_cases):
	m = int(input())
	row1 = [int(x) for x in input().split(" ")]
	row2 = [int(x) for x in input().split(" ")]
	print(solve(m, [row1, row2]))