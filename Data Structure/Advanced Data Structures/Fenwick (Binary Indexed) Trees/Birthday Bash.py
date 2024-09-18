'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

from string import ascii_lowercase
import time
import sys
import math
input = sys.stdin.readline
mod, infi = 1000000007, sys.maxsize
from collections import deque, Counter, defaultdict as dd
from heapq import heappop, heappush, heapify
from itertools import accumulate
from operator import mul, add, sub, truediv, floordiv, lt, le, eq, ne, gt, xor, concat, getitem, pow, lshift
inty    =lambda: int(input())
stringy =lambda: input().strip()
normal  =lambda: input().split()
mappy   =lambda: map(int,input().strip().split())
fmappy  =lambda: map(float,input().strip().split())
listy   =lambda: list(map(int,input().strip().split()))
tick    =lambda: time.perf_counter()
logg    =lambda a, b: math.log2(a) / math.log2(b)
acc     =lambda x: list(accumulate(x))
sign    =lambda x, y: x >= 0 and y >= 0 or x < 0 and y < 0
class BIT:
    def __init__(self, n):
        self.n = n + 1
        self.tree = [0 for _ in range(self.n)]
    
    def update(self, idx, val):
        idx += 1
        while idx < self.n:
            self.tree[idx] += val
            idx += idx&-idx
    
    def query(self, idx):
        idx += 1
        total = 0
        while idx:
            total += self.tree[idx]
            idx -= idx&-idx
        return total
T = inty()
for _ in range(T):
    n, q = mappy()
    s = [i for i in stringy()] 
    mapping = list(ascii_lowercase) + ['a']
    tree = BIT(n)
    for _ in range(q):
        t, x = mappy()
        if t == 1:
            tree.update(x, 1)
            tree.update(n - x, -1)
        else:
            cnt = tree.query(x)
            if cnt & 1:
                x = n - x - 1
            
            if s[x] == 'z':
                s[x] = 'a'
            else:
                s[x] = mapping[mapping.index(s[x]) + 1]
    for i in range(n // 2):
        cnt = tree.query(i)
        if cnt & 1:
            s[i], s[n - i - 1] = s[n - i - 1], s[i]
    print(''.join(s))
