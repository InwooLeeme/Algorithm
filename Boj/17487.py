S = input()
lfli = 'qwertyasdfgzxcvb'
rili = 'uiophjklnm'
lf, ri, other = 0, 0, 0

for i in S:
    if i.isupper():
        other += 1
for i in S.lower():
    if i in lfli:
        lf += 1
    elif i in rili:
        ri += 1
    else:
        other += 1

while other != 0:
    if lf <= ri:
        lf += 1
    else:
        ri += 1
    other -= 1
print(lf, ri, sep=" ")
