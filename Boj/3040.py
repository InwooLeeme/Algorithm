import itertools

li = (int(input()) for i in range(9))
ret = []
for j in list(itertools.combinations(li, 7)):
    if(sum(j) == 100):
        ret = j
        break
for j in ret:
    print(j)
