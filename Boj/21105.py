from decimal import Decimal
T = int(input())
for _ in range(T):
    p, c = map(Decimal, input().split())
    o = 100*p / (100 + c)
    print("%.5f" % o)
