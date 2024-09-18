'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

from sys import stdin
def xSum(n, m) : 
    res = 0
    multiplier = 1
    bit_sum = 0
    while (n or m) : 
        bit_sum = ((n % 10) + (m % 10))
        bit_sum = bit_sum % 10
        res = (bit_sum * multiplier) + res 
        n = n // 10
        m = m // 10 
        multiplier = multiplier * 10
    return res
case = int(stdin.readline())
for i in range(case):
    n1 = int(stdin.readline())
    n2 = int(stdin.readline())
    print(abs(xSum(n1,n2) - (n1+n2)))
