K = int(input())
N = int(input())
f = 0
for i in range(1, N):
    print(i)
    f += i
print(K - f)
