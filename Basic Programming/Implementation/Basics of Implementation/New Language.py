'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def toint(s):
    return int(s.replace('9','8'), 9)
 
def tostr(n):
    digits = '012345679'
    s = ''
    while n:
        s = digits[n%9] + s
        n = n//9
    return s or '0'
 
t = int(input())
for x in range(t):
    s = input()
    if '+' in s:
        a, b = map(toint, s.split('+'))
        print(tostr(a+b))
    elif '-' in s:
        a, b = map(toint, s.split('-'))
        print(tostr(a-b))
    elif '*' in s:
        a, b = map(toint, s.split('*'))
        print(tostr(a*b))
    elif '/' in s:
        a, b = map(toint, s.split('/'))
        print(tostr(a//b))
