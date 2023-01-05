A = int(input())
B = input()
S = B[::-1]
print(A)
print(B)
for i in range(len(B)):
    print(A * int(S[i]))
print(A*int(B))
