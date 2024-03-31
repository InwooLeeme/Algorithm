N = int(input())
f = 1
for i in range(1, N + 1):
    f *= i
S = str(f)
for i in range(len(S) - 1, -1, -1):
    if S[i] != '0':
        print(S[i])
        break
