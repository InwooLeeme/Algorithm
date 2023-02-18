#print(bytes.fromhex('68656c6c6f').decode('utf-8'))
while 1:
  try:
    S = input()
    print(bytes.fromhex(S).decode('utf-8'))
  except:
    break
