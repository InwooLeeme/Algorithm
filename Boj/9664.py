N = int(input())
O = int(input())
lft = O // (N - 1)
ret = O + lft
if(O - lft * (N - 1) == 0):
    print(ret - 1)
    print(ret)
else:
    print(ret)
    print(ret)
