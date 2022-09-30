S = input()
li = [*S]
ret = ""
for i in range(0, len(S)):
  if i % 2 != 0:
    ret += S[i]
  else:
    cur = int(li[i])
    temp = 0
    cur *= 2
    while cur:
      temp += cur % 10
      cur //= 10
    ret += str(temp)
if sum(list(map(int, ret))) % 10 == 0: print("DA")
else: print("NE")