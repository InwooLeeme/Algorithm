N = int(input())
for _ in range(1, N + 1):
    S = input()
    S = S.lower()
    li = [0] * 26
    for j in S:
        if j.isalpha():
            li[ord(j) - 97] += 1
    if min(li) >= 3:
        print("Case %d: Triple pangram!!!" % _)
    elif min(li) >= 2:
        print("Case %d: Double pangram!!" % _)
    elif min(li) >= 1:
        print("Case %d: Pangram!" % _)
    else:
        print("Case %d: Not a pangram" % _)
