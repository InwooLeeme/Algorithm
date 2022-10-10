import sys
input = sys.stdin.readline
while 1:
  try:
    N = int(input())
    f = "1"
    cur = "1"
    while 1:
      if(int(f) % N == 0):
        print(len(f))
        break
      f += cur
  except:
    break