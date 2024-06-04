import math
n,m,k = map(int, input().split())
ret = 0
for i in range(k, m + 1):
    ret += (math.comb(m, i) * math.comb(n - m, m - i))
print(ret / math.comb(n, m))
