N = int(input())
sum, M = 0, N
li = list(map(int, input().split()))
for x in li:
    if(x == -1):
        M -= 1
    else:
        sum += x
print(sum / M)
