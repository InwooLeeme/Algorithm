N, K = map(int, input().split())
D, S = map(int, input().split())
ret = ((D * N) - (S * K)) / (N - K)
if 0 <= ret and ret <= 100:
    print(ret)
else:
    print("impossible")
