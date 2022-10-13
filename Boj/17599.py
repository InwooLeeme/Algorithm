import sys
input = sys.stdin.readline
N = int(input())
li = map(int, input().split())
print(len(set(li)))
