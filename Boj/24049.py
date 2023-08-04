import sys
input = sys.stdin.readline

n, m = map(int, input().split())
v = [[-1] * (m + 1) for _ in range(n + 1)]
c = list(map(int, input().split()))
r = list(map(int, input().split()))
for i in range(1, n + 1):
  v[i][0] = c[i - 1]
for j in range(1, m + 1):
  v[0][j] = r[j - 1] 
for i in range(1, n + 1):
  for j in range(1, m + 1):
    v[i][j] = v[i][j - 1] ^ v[i - 1][j] 
print(v[n][m])
