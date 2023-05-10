map = dict()
li = []
while True:
  try:
    S = input()
    li.append(S)
  except: break
for i in li:
  a = "".join(i)
  b = "".join(sorted(a))
  if b in map: map[b] += [a]
  else: map.update({b:[a]})
ret = sorted([sorted(val) for k, val in map.items()], key = lambda x : (-len(x), x))
for i in ret[:5]:
  print("Group of size {}:".format(len(i)), end = " ")
  print(*sorted(list(set(i))), sep = " ", end = " .\n")
