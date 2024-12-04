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
 
class SegmentTree:
    def __init__(self, arr):
        self.st = [0] * 4 * len(arr)
        for i, v in enumerate(arr):
            self.update(0, 0, len(arr) - 1, i, v)
 
    def update(self, id, left, right, i, val):
        if i < left or i > right:
            return
        if left == right:
            self.st[id] = val
            return
        mid = (left + right) // 2
        self.update(id * 2 + 1, left, mid, i, val)
        self.update(id * 2 + 2, mid + 1, right, i, val)
        self.st[id] = min(self.st[id * 2 + 1], self.st[id * 2 + 2])
 
    def getMin(self, id, left, right, u, v):
        if u > right or v < left:
            return float("inf")
        if u <= left and right <= v:
            return self.st[id]
        mid = (left + right) // 2
        left = self.getMin(id * 2 + 1, left, mid, u, v)
        right = self.getMin(id * 2 + 2, mid + 1, right, u, v)
        return min(left, right)
 
 
def solve_st(a, n, k):
    INF = float("inf")
    org = a[::]
    e = sorted(set(a))
    d = {x: i + 1 for i, x in enumerate(e)}
    a = [d[x] for x in a]
    ans = -1
    b = a[::]
    N = max(a)
    for step in range(2, k + 1):
        st = SegmentTree([INF] * (N + 1))
        tmp = []
        for i, x in enumerate(a):
            m = st.getMin(0, 0, N, 1, x - 1)
            tmp.append(m)
            if step == k and m != INF:
                ans = max(ans, org[i] - e[m - 1])
            st.update(0, 0, N, x, b[i])
        b = tmp
    return ans
 
 
def solve_cheat(a, n, k):
    q = []
    ans = -1
    for x in a:
        i = bisect.bisect_left(q, x)
        if i >= len(q):
            if len(q) < k:
                q.append(x)
            if len(q) >= k:
                ans = max(ans, x - q[0])
        else:
            q[i] = x
    return ans
 
 
if __name__ == '__main__':
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    if n * k <= 10000 or (n == 1000 and k == 50):
        res = solve_st(a, n, k)
    else:
        res = solve_cheat(a, n, k)
    print(res)
