'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

class FenwickTree:
    def __init__(self, n):
        self.a = [0] * (n + 1)
        self.n = n
 
    def sum(self, i):
        res = 0
        while i > 0:
            res += self.a[i]
            i -= (i & -i)
        return res
 
    def update(self, i, x):
        while i <= self.n:
            self.a[i] += x
            i += (i & -i)
 
 
def solve(n, s):
    if 'a' not in s:
        return 0
    bit = FenwickTree(2 * n + 1)
    bit.update(n, 1)
    count = 0
    ans = 0
    for c in s:
        if c == 'a':
            count += 1
        elif c == 'c':
            count -= 1
        val = count + n
        ans = (ans + bit.sum(val - 1)) % mod
        bit.update(val, 1)
    return ans
 
 
mod = 10 ** 9 + 7
N = int(input())
S = input()
 
out_ = solve(N, S)
print(out_)
