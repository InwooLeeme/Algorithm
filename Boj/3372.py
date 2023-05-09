N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
D = [[0] * N for _ in range(N)]
D[0][0] = 1

for i in range(N):
  if board[0][i] + i < N:
    D[0][board[0][i] + i] += D[0][i]
  if board[0][i] < N:
    D[board[0][i]][i] += D[0][i]

for i in range(1, N):
  for j in range(N):
    if i == N - 1 and j == N - 1:
      break
    if i + board[i][j] < N:
      D[i + board[i][j]][j] += D[i][j]
    if j + board[i][j] < N:
      D[i][j + board[i][j]] += D[i][j]
print(D[N - 1][N - 1])