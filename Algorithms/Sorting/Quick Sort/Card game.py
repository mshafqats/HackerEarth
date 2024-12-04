'''
=====================
|  ID:   mshafqats  |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

from sys import stdin
 
def main ():
    read = stdin.readline
    an = int (read ())
    a = list (map (int, read ().split ()))
    bn = int (read ())
    b = list (map (int, read ().split ()))
    target = max (b) + 1
    res = 0
    for v in a:
        if v < target: res += target - v
    print (res)
 
if __name__ == "__main__": main ()
