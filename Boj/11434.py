T = int(input())
for i in range(1, T + 1):
  n, w, e = map(int, input().split())
  ret = 0
  for _ in range(n):
    a,b,c,d = map(int, input().split())
    ret += max(a * w + c * e, d * e + b * w)
  print(f"Data Set {i}:")
  print(ret)
  print()