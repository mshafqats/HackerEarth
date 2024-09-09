'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

t = int(input())

while t != 0:
    n = int(input())
    arr = list(map(int, input().split(' ')))
    arr.sort()
    minimum = arr[0] ^ arr[1]
    for i in range(1, n - 1):
        temp = arr[i] ^ arr[i + 1]
        if temp < minimum:
            minimum = temp

    print(minimum)
    print("")
    t -= 1