from decimal import Decimal
C = Decimal(input())
L = int(input())
ret = 0
for _ in range(L):
    a, b = map(Decimal, input().split())
    ret += (a * b * C)
print("%.6f" % ret)
