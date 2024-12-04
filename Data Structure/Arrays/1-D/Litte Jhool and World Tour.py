'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

import sys
 
for line in sys.stdin:
    t = int(line)
    for _ in range(t):
        n, q = map(int, sys.stdin.readline().split())
        flag = False
        for _ in range(q):
            x, y = map(int, sys.stdin.readline().split())
            if x == y:
                flag = True
                break
            elif x > n and x > y:
                if x - y > n:
                    flag = True
        if flag:
            print("NO")
        else:
            print("YES")
