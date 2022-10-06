while True:
    n, m, k = map(int, input().split())
    if n == 0 and m == 0:
        break
    f = n - m - k
    if n//2 + 1 - m <= f:
        print(max(0, n//2 + 1 - m))
    else:
        print(-1)
