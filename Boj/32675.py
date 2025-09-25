n, k = map(int, input().split())
v = [[0 for i in range(0, n + 1)] for j in range(0, n + 1)]
for i in range(0, n + 1):
    for j in range(0, i + 1):
        if j == 0 or j == i: v[i][j] = 1
        else: v[i][j] = v[i - 1][j - 1] + v[i - 1][j]
        v[i][j] %= k;
res = 0
for i in range(0, n + 1):
    for j in range(0, i + 1):
        if v[i][j] % k == 0: res += 1
print(res)
