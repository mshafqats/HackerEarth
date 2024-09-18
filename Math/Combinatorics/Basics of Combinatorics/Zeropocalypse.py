'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

MOD = 10**9 + 7
LIM = 10**6 + 100
 
f = [1]
for i in range(1, LIM):
    f.append(f[-1]*i % MOD)
 
def C(n, r):
    if r < 0 or n < r:
        return 0
    den = f[r] * f[n-r] % MOD
    ans = f[n] * pow(den, MOD-2, MOD) % MOD
    return ans
 
def solve(A, N):
    if N==0:
        return -1
    pind = -1
    pnum = 0
    ans = 1
    for ind, num in enumerate(A):
        if num == 0:
            continue
        
        diff = num - pnum - 1
        gap = ind - pind - 1
 
        cnr = C(diff, gap)
        if cnr == 0:
            return 0
        ans = ans * cnr % MOD
        pind = ind
        pnum = num
    if A[-1] == 0:
        return -1
    return ans
 
for case in range(int(input())):
    try:
        N = int(input())
        A = list(map(int, input().split()))
        print(solve(A, N))
    except:
        print(-1)
