import itertools

T = int(input())
for i in range(1, T + 1):
    S = input()
    li = [x for x in S]
    ret = list(map(''.join, itertools.permutations(li)))
    print("Case # %d:"%i)
    for _ in ret:
        print(_)
