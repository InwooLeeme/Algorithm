import sys
import itertools
input = sys.stdin.readline
v = list(map(int, input().rstrip().split()))
mx = 0
for i in itertools.permutations(v):
    ret = ""
    for j in i:
        ret += str(j)
    mx = max(mx, int(ret))
print(mx)
