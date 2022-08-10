def Sol():
    m, n = map(int, input().split())
    li = [list(map(int, input().split())) for i in range(n)]
    f = []
    for i in range(m):
        k = 1
        for j in range(n):
            k *= li[j][i]
        f.append(k)
    mx = max(f)
    idx = 0
    for i in range(0, len(f)):
        if mx == f[i]:
            idx = i + 1
    return idx


T = int(input())
for _ in range(T):
    print(Sol())
