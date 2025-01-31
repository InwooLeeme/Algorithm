from decimal import Decimal, getcontext
getcontext().prec = 100
def Sol():
    a,b,c = 0,0,0
    N = Decimal(input())
    S = Decimal('0')
    for _ in range(4):
        x, y, z = map(Decimal, input().split())
        S += Decimal((a - x)**2 + (b - y)**2 + (c - z)**2).sqrt()
        a, b, c = x, y, z
    if S <= N: print("YES")
    else: print("NO")
T = int(input())
for _ in range(T):
    Sol()
