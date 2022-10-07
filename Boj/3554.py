N = int(input())
li = list(map(int, input().split()))
Q = int(input())
for i in range(Q):
    k, a, b = map(int, input().split())
    if k == 1:
        for j in range(a - 1, b):
            li[j] = (li[j]**2) % 2010
    else:
        ret = 0
        for j in range(a - 1, b):
            ret += li[j]
        print(ret)
