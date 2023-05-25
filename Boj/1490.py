import sys
import math
input = sys.stdin.readline

N = int(input().rstrip())
li = []
for i in str(N):
    if i != '0':
        li.append(int(i))
li = list(set(li))
for i in range(1, len(li)):
    li[0] = math.lcm(li[0], li[i])
lc = li[0]
if N % lc == 0:
    print(N)
else:
    cnt = 1
    check = 0
    while True:
        for i in range(0, 10**cnt):
            if int(str(N) + "0"*(cnt - len(str(i))) + str(i)) % lc == 0:
                print(int(str(N) + "0"*(cnt - len(str(i))) + str(i)))
                exit(0)
        cnt += 1
