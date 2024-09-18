'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

MOD = 1_000_000_007
 
def C(n, k):
    return mul(f(n), fe(mul(f(k), f(n - k)), MOD - 2))
 
def f(n):
    res = 1
    for i in range(n):
        res = mul(res, i + 1)
    return res
 
def fe(x, y):
    if y == 0:
        return 1
    if y % 2 == 1:
        return mul(fe(x, y - 1), x)
    res = fe(x, y // 2)
    return mul(res, res)
 
def add(x, y):
    x += y
    while x < 0:
        x += MOD
    while x >= MOD:
        x -= MOD
    return x
 
def mul(x, y):
    return x * y % MOD
 
t = int(input())
while t > 0:
    t -= 1
    n, k = map(int, input().split())
    if k > n:
        print(1)
    else:
        print(mul(add(C(n + k - 1, k), -C(n, k)), fe(C(n + k - 1, k), MOD - 2)))
