import math


def Catalan(n):
    return math.factorial(n * 2) // (math.factorial(n) * math.factorial(n + 1))


a, b = map(int, input().split())
print(Catalan(abs(b - a)))
