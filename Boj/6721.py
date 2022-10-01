def Rev(a):
  return int(str(a)[::-1])
T = int(input())
for _ in range(T):
  a,b = map(int ,input().split())
  print(Rev(str(Rev(a) + Rev(b))))