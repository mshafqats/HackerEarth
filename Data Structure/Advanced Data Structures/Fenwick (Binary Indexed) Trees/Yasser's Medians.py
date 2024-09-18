'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

import bisect 
n,k = list(map(int,input().split()))
 
A = list(map(int,input().split()))
 
L = [0]
 
for i in range(k-1):
    bisect.insort_left(L,A[i])
res = 0
M = 10**9 + 7
for i in range(k-1,n):
    bisect.insort_left(L,A[i])
    m = L[(k+1)//2]
    res = max(res,m)
    j = bisect.bisect_left(L,A[i-k+1])
    del L[j]
 
print(pow(n,res,M))
