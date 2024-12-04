'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

import math
mod = 1000000007
n, m = map(int, input().split())
print (pow(2*(n+1), m, mod) * pow(n+1, mod-2, mod) % mod * (n+1-m) % mod)
