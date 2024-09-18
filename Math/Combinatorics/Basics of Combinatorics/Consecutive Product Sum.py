'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

modV = 10 ** 9 + 7
T = int(input())
res = []
index = 1
power2 = [0] * (5 * 10 ** 5 + 1)
power2[0] = 1
for i in range(1, 5 * 10 ** 5 + 1):
    power2[i] = (power2[i - 1] * 2) % (10 ** 9 + 7)
 
 
def helper(arr):
    tempRes = 0
    n = len(arr)
    temp = int(arr[n - 1])
    for i in range(n - 2, -1, -1):
        w = (power2[i] * int(arr[i]) * temp) % modV
        tempRes += w
        tempRes %= modV
        temp += (int(arr[i]) * power2[n - 1 - i]) % modV
        temp %= modV
    return tempRes
 
while index < 2 * T:
    N = int(input())
    index += 1
    arr = input()
    index += 1
    res.append(str(helper(arr.split())))
 
print('\n'.join(res))