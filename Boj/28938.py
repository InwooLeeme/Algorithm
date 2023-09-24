n = int(input())
v = map(int, input().split())
t1,t2 = 0,0
for i in v:
    if i == 1: t1 += 1
    elif i == -1: t2 += 1
if t1 > t2: print("Right")
elif t1 == t2: print("Stay")
else: print("Left")
