'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def increasingSeq(l,a):
    from math import ceil   
    b = [a[0]]
    for i in range(1,l):
        z = ceil(b[-1]/a[i])
        b.append(z*a[i])
    return (' '.join(map(str,b)))
 
tst = int(input())
for i in range(tst):
    len_arr = int(input())
    x =list(map(int, input().split()))
    print(increasingSeq(len_arr,x))
