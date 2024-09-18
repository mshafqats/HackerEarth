'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def calculate_ans(n, s):
    f = [0] * (2 * n + 5)
    f[1] = 1
    mod = 10 ** 9 + 7
 
    for i in range(3, n + n + 1):
        f[i] = f[i - 2] * i % mod
 
    ans = 0
    for i in range(2, n + n + 1):
        cnt = f[n + n - 1]
        cnt = (cnt + mod - (f[i - 2] * f[n + n - i] % mod)) % mod
        ans = (ans + cnt * (s[i - 1] - s[i - 2])) % mod
 
    return ans
 
n = int(input())
s = list(map(int, input().split()))
result = calculate_ans(n, s)
print(result)
