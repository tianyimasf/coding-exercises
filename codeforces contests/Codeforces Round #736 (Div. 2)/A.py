# both methods are correct, however excessive

# memory space exceeded
def solve(case):
	sol = [-1 for i in range(0, case)]
	base1, base2 = -1, -1
	for i in range(1, case+1):
		remainder = case % i
		if remainder not in sol:
			sol[i] = remainder
		elif remainder in sol and remainder is not case:
			base1 = sol.index(remainder)
			base2 = i
			break
	return base1, base2

# time limit exceeded
def solve2(case):
	base1, base2 = -1, -1
	for i in range(1, case+1):
		a = case - i
		hit = False
		for p in range(2, a+1):
			rem = a % p
			if rem == 0 and hit == False:
				base1 = p
				hit = True
			elif rem == 0 and hit == True:
				base2 = p
				return base1, base2

# since P is a prime, P-1 is always an even composite number. So we can simply pick 2 and P-1 
def solve_correct(case):
	return 2, case-1

test_cases = int(input())

for i in range(0, test_cases):
	case = int(input())
	base1, base2 = solve2(case)
	print(base1, base2)