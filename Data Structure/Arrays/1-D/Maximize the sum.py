'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

from collections import Counter
 
T = int(input())
for _ in range(T):
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    freq = Counter(A)
    final_A = [k * v for k, v in freq.items() if k>0]
    final_A.sort(reverse=True)
    print(sum(final_A[:K]))
