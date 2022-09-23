S = input()
N = int(input())
li = sorted([input() for i in range(N)])
mx = idx = 0
for i in range(N):
    L = S.count('L') + li[i].count('L')
    O = S.count('O') + li[i].count('O')
    V = S.count('V') + li[i].count('V')
    E = S.count('E') + li[i].count('E')
    P = ((L+O) * (L+V) * (L+E) * (O+V) * (O+E) * (V+E)) % 100
    if P > mx:
        mx = P
        idx = i
print(li[idx])
