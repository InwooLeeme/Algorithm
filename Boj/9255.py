import sys
input = sys.stdin.readline

T = int(input())
for tc in range(1, T + 1):
    n,m = map(int, input().rstrip().split())
    lines = [tuple(map(int, input().rstrip().split())) for _ in range(m)]
    k = int(input())
    friends = set()
    for i,j in lines:
        if i == k:
            friends.add(j)
        elif j == k:
            friends.add(i)
    friends = sorted(friends)
    print(f"Data Set {tc}:")
    print(*friends)
    if tc != T:
        print()