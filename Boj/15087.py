def get_sum(s):
    return sum([ord(i) - 65 for i in s])


def rotate_chr(s, n):
    return chr((ord(s) - 65 + n) % 26 + 65)


def Div(s):
    return s[: len(s) // 2], s[len(s) // 2:]


def Rotate(s, n):
    return "".join([rotate_chr(i, n) for i in s])


def merge(a, b):
    return "".join([rotate_chr(a[i], ord(b[i]) - 65) for i in range(len(a))])


S = input()
A, B = Div(S)
print(merge(Rotate(A, get_sum(A)), Rotate(B, get_sum(B))))
