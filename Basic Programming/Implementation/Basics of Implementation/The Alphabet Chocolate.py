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

def solve(s):
    n = len(s)
    vowel = "aeiouAEIOU"
    ans = 0
    for i, c in enumerate(s):
        if c in vowel:
            ans += (i + 1) * (n - i)
    return ans

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input()
        res = solve(s)
        print(res)
