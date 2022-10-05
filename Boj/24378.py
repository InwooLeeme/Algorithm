m = int(input())
n,a,b,c = map(int, input().split())
if(m % 2):
  print(max(0, a + b + c - 2 * n))
else:
  print(min(a, b, c))  