'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def no(n):
    s = ''
    cons = 0
    for x in range (39,-1,-1):
        if fibo[x] <= n:
            cons = 1
            s += '1'
            n -= fibo[x]
            continue
        if cons == 1:
            s += '0'
    return s
 
fibo = [0]*40
fibo[0] = 1
fibo[1] = 2
for x in range (2,40):
    fibo[x] = fibo[x-1] + fibo[x-2]
for _ in range(int(input())):
    n = int(input())
    ans = no(n)
    print(ans)
