import math, sys
input = sys.stdin.readline
def Sol(x):
  return math.comb(10 - 1 + x, x)
T = int(input())
for _ in range(T):
  print(Sol(int(input())))