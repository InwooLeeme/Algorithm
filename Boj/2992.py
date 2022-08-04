import itertools
import sys
input = sys.stdin.readline


def Sol():
    S = input().rstrip()
    mn = 1e9
    for i in list(itertools.permutations(S)):
        cur = int("".join(i))
        if cur > int(S):
            mn = min(mn, cur)
    if mn == 1e9:
        return 0
    else:
        return mn


print(Sol())
