import sys
input = sys.stdin.readline

n, k = map(int, input().split())
li = list(int(input()) for i in range(n))
ret = 0
for i in range(n):
    for j in range(i + 1, n):
        if li[i] + li[j] <= k:
            ret += 1
print(ret)
