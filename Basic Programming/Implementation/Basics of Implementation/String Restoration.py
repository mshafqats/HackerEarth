'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def valid_prefix(p,arr):
    c = 0
    if p[-1] > 26:
        ans = -1
        return ans
    elif p[0] > 1:
        ans = -1
        return ans
    else:
        for i in range(1,n):
            if not (p[i]-p[i-1] in [0,1]):
                return -1
        for i in range(n):
            if p[i] == c+1:
                c = c+1
                arr.append(chr(96+c))
            else:
                arr.append('a')
        ans = ''.join(arr)
        return ans
 
t = input()
 
while t:
    t = t-1
    n = input()
    arr = []
    p = map(int,raw_input().split())
    data = valid_prefix(p,arr)
    print data
