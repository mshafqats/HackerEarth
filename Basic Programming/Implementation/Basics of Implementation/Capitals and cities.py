'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

n, k = map(int, input().split())
l = list(map(int, input().split()))
l1 = l[:]
l.sort()
nu = len(l)
num = nu//2
y = 0
p = 0
if nu % 2 != 0:
    p = l[num]
    index = l1.index(p)
    for i in range(num):
        y = y + l[num] - l[i] + l[nu - 1 - i] - l[num]
    t = abs(y - k)
else:
    num1 = num - 1
    num2 = num
    index1 = 0
    index2 = 0
    for i in range(num1):
        y = y + l[num1] - l[i]
    for i in range(num1 + 1, nu):
        y = y + l[i] - l[num1]
    p1 = l[num1]
    p2 = l[num2]
    if l1.index(p1) < l1.index(p2):
        index = l1.index(p1)
    else:
        index = l1.index(p2)
    t = abs(y - k)
if k < y:
    print(str(index + 1) + " " + str(t))
else:
    if (k - y) % 2 == 0:
        t = 0
        for i in range(0, nu):
            q = 0
            for j in range(0, i):
                q = q + abs(l1[i] - l1[j])
            for j in range(i + 1, nu):
                q = q + abs(l1[i] - l1[j])
            if (k - q) % 2 == 0:
                index = i
                print(str(index + 1) + " 0")
                break
    else:
        for i in range(0, nu):
            q = 0
            for j in range(0, i):
                q = q + abs(l1[i] - l1[j])
            for j in range(i + 1, nu):
                q = q + abs(l1[i] - l1[j])
            if (k - q) % 2 == 0 and abs(k - q) <= t:
                t = 0
                index = i
                p = 6
                break
        if p == 6:
            print(str(index + 1) + " " + str(t))
        else:
            print(str(index + 1) + " 1")
