'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

T = int(input())

def minimum(K, N):
    sayac = 0
    while N > 0:
        N = N // (K+1)
        sayac += 1
    return sayac

for i in range(T):
    K, N = map(int, input().split())
    print(minimum(K, N))
