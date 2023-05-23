import sys
import re

input = sys.stdin.readline

def f(string):
  ret = re.findall(r"\w+", string)
  return ret

while True:
    try:
        N = int(input())
        d = dict()
        while True:
            S = input().rstrip()
            if S == "EndOfText": break
            lowerS = S.lower()
            for word in f(lowerS):
                if word in d:
                    d[word] += 1
                else:
                    d[word] = 1
        ret = []
        for k, v in d.items():
            if v == N:
                ret.append(k)
        if len(ret) == 0:
            print("There is no such word.")
        else:
            ret.sort()
            for word in ret:
                print(word)
        print()
    except:
        break
