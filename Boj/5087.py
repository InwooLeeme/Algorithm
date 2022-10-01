while True:
    li = input().split()
    if li[0] == "#":
        break
    c, d = 0, 0
    for i in li[:-1]:
        if i in ['A', '3', '5', '7', '9']:
            c += 1
        else:
            d += 1
    if c > d:
        print("Cheryl")
    elif c == d:
        print("Draw")
    else:
        print("Tania")
