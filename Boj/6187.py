import itertools
import sys
input = sys.stdin.readline
k, n = map(int, input().split())
li = [int(input()) for x in range(n)]
mx = 0
for i in range(n, 0, -1):
    S = 0
    for j in list(itertools.combinations(li, i)):
        S = sum(j)
        if S <= k:
            mx = max(mx, S)
print(mx)
