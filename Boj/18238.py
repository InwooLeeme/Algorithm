S = input()
ret = 0
st = ord('A')
for i in range(len(S)):
    lo, hi = st - ord(S[i]), ord(S[i]) - st
    if(lo < 0):
        lo += 26
    if(hi < 0):
        hi += 26
    ret += min(lo, hi)
    st = ord(S[i])
print(ret)
