import sys
input = sys.stdin.readline
n = input()

if "0" not in n:
    print(-1)

else:
    sum = 0
    for i in range(len(n)):
        sum += int(n[i])

    if sum % 3 != 0:
        print(-1)

    else:
        sorted_num = sorted(n, reverse=True)
        answer = "".join(sorted_num)
        print(answer)
