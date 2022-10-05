T = int(input())
for i in range(1, T + 1):
    li = list(map(int, input().split()))
    li.sort()
    print(f"Case #{i}: {li[4]}")
