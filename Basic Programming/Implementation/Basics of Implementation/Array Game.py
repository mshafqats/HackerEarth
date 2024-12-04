'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

t = int(input())
 
for _t in range(t):
    n=int(input())
    a=list(map(int, input().split()))
    maximum = []
    moves = prev_max = 0
 
    for i in a:
        if i > prev_max:
            prev_max = i
        maximum.append(prev_max)
    last_min = a[-1]
 
    for i in range(n-2, -1, -1):
        if a[i] < last_min:
            if maximum[i] < last_min:
                moves += 1
 
            last_min = a[i]
 
    if moves %2 == 0:
        print("Ashish")
    else:
        print("Jeel")
