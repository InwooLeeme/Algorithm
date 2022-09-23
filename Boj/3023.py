R, C = map(int, input().split())
li = [list(map(str, input())) for _ in range(R)]
A, B = map(int, input().split())
for i in li:
    i.extend(i[::-1])
S = []
for i in reversed(li):
    S.append(list(i))
li.extend(S)
if(li[A - 1][B - 1] == '#'):
    li[A - 1][B - 1] = '.'
else:
    li[A - 1][B - 1] = '#'
for i in li:
    print(*i, sep='')
