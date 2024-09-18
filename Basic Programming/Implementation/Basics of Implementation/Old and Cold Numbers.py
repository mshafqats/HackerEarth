'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

from itertools import accumulate
from sys import stdin, stdout
input = stdin.readline
def old(x):
    x = int(x)
    if x % sum(divmod(x, 2)):
        return 0
    return 1
for _ in range(int(input())):
    n = int(input())
    a = list(accumulate([0] + list(map(old, input().split()))))
    q = int(input())
    res = ['0'] * q
    for tc in range(q):
        l, r = map(int, input().split())
        o = a[r] - a[l - 1]
        c = r - l + 1 - o
        if c > o:
            res[tc] = str((c - o + 1) // 2)
    stdout.write('\n'.join(res) + '\n')
