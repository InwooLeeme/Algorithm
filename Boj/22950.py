N = int(input())
S = input()
K = int(input())
A = int(S, 2)
if A % (2**K) == 0:
    print("YES")
else:
    print("NO")
