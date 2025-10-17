n = int(input())
l = list(map(int, input().split()))
r = list(map(int, input().split()))
res = 0
for i in range(n): res += abs(l[i] - r[i])
print(res // 2)
