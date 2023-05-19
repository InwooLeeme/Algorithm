S = input().split('x')
if len(S) == 1:
    print(0)
else:
    if S[0] == '':
        print('1')
    elif S[0] == '-':
        print("-1")
    else:
        print(S[0])
