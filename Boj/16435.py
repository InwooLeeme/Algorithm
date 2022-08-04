import sys
input = sys.stdin.readline

n, l = map(int, input().split())
li = list(map(int, input().split()))
li.sort()
for i in li:
    if l >= i:
        l += 1
print(l)
