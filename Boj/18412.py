N,A,B = map(int, input().split())
S = input()
ret = S[:A - 1] + S[A - 1:B][::-1] + S[B:]
print(ret)