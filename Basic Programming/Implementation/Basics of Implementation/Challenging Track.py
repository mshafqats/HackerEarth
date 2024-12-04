'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

from collections import deque
 
def hurdle(p,hur):
    p -= hur.popleft()
    if p < 0:
        return ['No',p]
    h = hur.popleft()
    if h & 1 == 0:
        h -= 1
    p -= h
    if p < 0:
        return ['No',p]
    i = 1
    while hur:
        h = hur.popleft()
        if h & 1 == 0:
            h -= 1
        h -= i
        if h < 0:
            h = 0
        p -= h
        if p < 0:
            return ['No', p]
        i += 1
    return ['Yes',p]
 
if __name__ == '__main__':
 
    for _ in range(int(input())):
        n,p = map(int,input().split())
        hur = deque(map(int,input().split()))
        res,p = hurdle(p,hur)
        if p >= 0:
            print(res,p)
        else:
            print(res)
