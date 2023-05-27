T = int(input())
for _ in range(1, T + 1):
  S = input()
  k = list(S)
  for i in range(len(k)):
    if k[i] == '/': k[i] = '//'
  ret = eval("".join(k))
  v = []
  for i in S:
    if i == '*' or i == '/':
      v.append(i)
  for i in S:
    if i == '+' or i == '-':
      v.append(i)
  print(f"Case #{_}:",end=' ')
  print(*v, ret)
