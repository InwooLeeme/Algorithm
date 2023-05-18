import sys
N, S = map(int, input().split())
v = [int(input()) for i in range(N)]
lo, hi = 0, sys.maxsize


def Check(mid):
    ret = 0
    for i in v:
        ret += (i // mid)
    return ret >= S


while(lo + 1 < hi):
    mid = lo + hi >> 1
    if(Check(mid)):
        lo = mid
    else:
        hi = mid
#print(lo, hi)
print(sum(v) - (lo * S))
