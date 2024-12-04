'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def binary_operation(x, y, arr):
    if x == 0 and y == 0:
        return arr[0]
    if x == 1 and y == 0:
        return arr[1]
    if x == 0 and y == 1:
        return arr[2]
    if x == 1 and y == 1:
        return arr[3]
 
T = int(input())
for _ in range(T):
    arr = list(map(int, input().split()))
    a_flag = True
    for i in range(2**3):
        x = (i & (2**0)) == (2**0)
        y = (i & (2**1)) == (2**1)
        z = (i & (2**2)) == (2**2)    
        if binary_operation(binary_operation(x,y, arr), z, arr) != binary_operation(x, binary_operation(y,z, arr), arr):
            a_flag = False
            break
    if a_flag:
        print("Yes")
    else:
        print("No")
