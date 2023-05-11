import sys
from fractions import Fraction
from decimal import *
input = sys.stdin.readline
tc = int(input())
for _ in range(tc):
    N = input()
    if not '(' in N:
        print(Fraction(Decimal(N)))
    else:
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
        print(Fraction(int(a) - int(b), int(div)))
