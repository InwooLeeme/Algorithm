import math

def Catalan(n):
  return math.factorial(n * 2) // (math.factorial(n) * math.factorial(n + 1))
N = int(input())
print(Catalan(N + 1))