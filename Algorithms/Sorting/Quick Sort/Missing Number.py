'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def Solve(arr):
    arr = sorted(arr)
    nex = 2
    for i in arr:
        if i >= nex:
            nex+=2
    return nex
T = int(input())
for _ in range(T):
    n = int(input())
    arr = map(int, input().split())
 
    out_ = Solve(arr)
    print (out_)
