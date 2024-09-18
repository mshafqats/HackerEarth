'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

import math
 
def fac(n):
    mod = 10**9 + 7
    rv = 1
    for i in range(2, n+1):
        rv = (rv * i) % mod
    return rv
 
def binom(n, k):
    if n < k:
        return 0
 
    mod = 10**9 + 7
    a = fac(n)
    b = fac(k)
    c = fac(n-k)
    b_inv = pow(b, mod-2, mod)
    c_inv = pow(c, mod-2, mod)
    return (a * b_inv * c_inv) % mod
 
l, r, n = (int(x) for x in input().split())
A = [max(int(x), 1) for x in input().split()]
 
d = r - l + 1 - sum(A) + n - 1
print(binom(d, n))
