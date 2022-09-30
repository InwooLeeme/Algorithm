n, m, k = map(int, input().split())
if m >= k:
    print(n * (m // k + k - 1))
else:
    print(n * m)
