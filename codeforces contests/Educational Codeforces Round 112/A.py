def solve(n):
    if (n<=6):
        return 15
    m = n if n%2==0 else n+1
    return int(5/2*m)
    
test_cases = int(input())

for i in range(0, test_cases):
    friends = int(input())
    print(solve(friends))