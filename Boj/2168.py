import sys,math
input = sys.stdin.readline
a,b = map(int, input().split())
g = math.gcd(a, b)
x,y = a // g, b // g
print(g * (x + y - 1))
