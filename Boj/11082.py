#import sys
from fractions import Fraction
from decimal import Decimal
#input = sys.stdin.readline
N = input()
if N.find('.') == -1:
    print(f"{N}/1")
    exit(0)
if N.find('(') == -1 and N.find('.') != -1:
    S = Fraction(Decimal(N))
    print(f"{S.numerator}/{S.denominator}")
    exit(0)
idx = N.find('.')
t1 = N.find('(')
t2 = N.find(')')
a, b = "", ""
for i in N:
    if i == ')' or i == '(' or i == '.':
        continue
    a += i
for i in N:
    if i == '(':
        break
    elif i == '.':
        continue
    b += i
div = '9' * (t2 - t1 - 1) + (t1 - idx - 1) * '0'
ret = Fraction(int(a) - int(b), int(div))
print(f"{ret.numerator}/{ret.denominator}")
