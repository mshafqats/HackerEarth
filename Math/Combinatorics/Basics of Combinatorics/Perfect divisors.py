'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

import collections
 
def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)
 
def modinv(a, m):
    g, x, y = egcd(a, m)
    return x % m
 
p = 10**9 + 7
 
max_n = 2 * 10**6
factor = [-1] * (max_n + 1)
for i in range(2, max_n + 1):
    if factor[i] == -1:
        for j in range(i, max_n + 1, i):
            factor[j] = i
 
exp = collections.defaultdict(int)
 
n = int(input())
for _ in range(n):
    x, y = (int(x) for x in input().split())
    while x > 1:
        f = factor[x]
        exp[f] += y
        x //= f
 
total = 1
for x in exp:
 
    y = exp[x] % p
    a = (x * x) % p
    b = y // 2
 
    base = (pow(a, b+1, p) - 1 + p) % p
    inv = modinv(a-1, p)
    term = (base * inv) % p
    total = (total * term) % p
print(total) 
