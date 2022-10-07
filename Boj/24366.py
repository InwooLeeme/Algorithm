N, K = map(int, input().split())
N -= 1
K -= 1
print(K - N % K)
