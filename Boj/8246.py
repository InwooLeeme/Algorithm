n, m, K = map(int, input().split())
print((((n//K) * (m//K)) - max(0, (n//K - 2) * max(0, m//K-2))))
