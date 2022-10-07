T = int(input())
for _ in range(T):
    N, D = map(int, input().split())
    ret = 0
    for i in range(N):
        a, b, c = map(int, input().split())
        if D <= (a * b / c):
            ret += 1
    print(ret)
