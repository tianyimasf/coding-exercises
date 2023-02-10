def onepass(asteroids):
    sol = []
    if len(asteroids) == 1:
        sol = asteroids
    skip = False
    for i in range(0, len(asteroids)-1):
        j = i+1
        a = asteroids[i]
        b = asteroids[j]
        if a > 0 and b < 0:
            if abs(a) > abs(b):
                if not skip:
                    sol.append(a)
                    skip = True
                else:
                    skip = False
            elif abs(a) < abs(b):
                sol.append(b)
                skip = True
            else:
                skip = True
        elif i == len(asteroids)-2:
            if skip:
                sol.append(b)
            else:
                sol = sol + [a, b]
        else:
            if skip:
                skip = False
            else:
                sol.append(a)
    return sol


class Solution:

    def asteroidCollision(self, asteroids):
        sol = onepass(asteroids)
        while sol != asteroids:
            asteroids = sol
            sol = onepass(asteroids)
        return sol
