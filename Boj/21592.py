import sys
input = sys.stdin.readline
N = int(input())
li = [input() for i in range(N)]
li.sort()
subS = []
for i in range(len(li[0])):
    for j in range(i + 1, len(li[0])):
        subS.append(li[0][i:j])
ret = 0
for i in subS:
    flag = 0
    for j in li:
        if not i in j:
            flag = 1
    if flag == False:
        ret = max(ret, len(i))
print(ret)
