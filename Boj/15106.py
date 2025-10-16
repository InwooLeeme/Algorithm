def f(x : int):
    res = 0
    d = 1
    while d <= x:
        v = x // d
        r = x // v
        S = (d + r) * (r - d + 1) // 2
        res += v * S
        d = r + 1
    return res
l, r = map(int, input().split())
print(f(r) - f(l - 1))
