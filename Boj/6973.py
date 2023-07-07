import math
import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    if(_ != 0):
        print()
    v = []
    while True:
        s = input().rstrip()
        if s == "":
            break
        v.append(s)
    d = {}
    for i in v:
        li = list(i.split())
        for j in range(len(li)):
            if j != 0:
                print(' ', end='')
            if d.get(li[j]):
                print(d[li[j]], end='')
            else:
                d[li[j]] = len(d) + 1
                print(li[j], end='')
        print()
