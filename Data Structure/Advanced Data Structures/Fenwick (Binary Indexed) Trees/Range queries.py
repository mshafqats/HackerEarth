'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

import math
import collections
import heapq
import bisect
import functools
import string
 
def solve(a, n):
    pass
 
if __name__ == '__main__':
    m = 10 ** 5
    xor = [1] * (m + 1)
    for i in range(2, m + 1):
        xor[i] = i ^ xor[i - 1]
    for i in range(2, m + 1):
        xor[i] ^= xor[i - 1]
    xor[0] = 0
    t = int(input())
    for _ in range(t):
        n = int(input())
        q = int(input())
        a = list(map(int, input().split()))
        pos = {x: i + 1 for i, x in enumerate(a)}
        res = []
        for _ in range(q):
            l, r = map(int, input().split())
            i = 1
            while i <= n and l <= pos[i] <= r:
                i += 1
            res.append(xor[i - 1])
        print(" ".join(map(str, res)))
