import sys
from math import sqrt
input = sys.stdin.readline

T = int(input())
li = []
for i in range(T):
    w, h = map(int, input().split())
    li.append([i + 1, sqrt(w ** 2 + h ** 2) / 77])
li.sort(key=lambda x: (-x[1], x[0]))
for i in li:
    print(i[0])
