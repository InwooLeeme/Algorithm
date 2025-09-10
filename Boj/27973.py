q = int(input())
cur = 1
a = 1
b = 0
for _ in range(q):
    v = list(map(int, input().split()))
    if(v[0] == 0):
        b += v[1]
    elif(v[0] == 1):
        a *= v[1]
        b *= v[1]
    elif(v[0] == 2):
        cur += v[1]
    else:
        print(a*cur + b)
