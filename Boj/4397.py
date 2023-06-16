import sys,math,decimal
input = sys.stdin.readline
while True:
  try:
    a,b,c,d = map(int, input().split())
    print("%.5f"%decimal.Decimal(math.comb(a, b) / math.comb(c, d)))
  except: break