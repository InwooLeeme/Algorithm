T = int(input())
for _ in range(T):
    b, p = list(map(float, input().split()))
    print(60*b/p-60/p, 60*b/p, 60*b/p+60/p)
