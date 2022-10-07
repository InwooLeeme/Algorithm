from decimal import Decimal
a, b, c, d = map(Decimal, input().split())
ret = min(a, b) + min(c, d)
print(int(Decimal(ret).sqrt()))
