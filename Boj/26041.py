li = list(map(str, input().split()))
K = input()
ret = 0
for i in li:
    if i.startswith(K) and i != K:
        ret += 1
print(ret)
