import sys
input = sys.stdin.readline

A = input()
B = input()
D = [[0]*1011 for i in range(1011)]
for i in range(1, len(A) + 1):
  for j in range(1, len(B) + 1):
    if A[i - 1] == B[j - 1]:
      D[i][j] = D[i - 1][j - 1] + 1
    else:
      D[i][j] = max(D[i - 1][j], D[i][j - 1])
print(D[len(A)][len(B)] - 1)