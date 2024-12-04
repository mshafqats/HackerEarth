'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

from math import pow
import sys
 
def main():
    FAST = lambda: sys.stdin.readline().rstrip()
    tc = int(input())
    
    for _ in range(tc):
        n = int(input())
        a = list(map(int, input().split()))
        m = {}
        l = 0
        ans = 0
 
        for i in range(n):
            if a[i] in m:
                if m[a[i]] >= l:
                    l = m[a[i]] + 1
            m[a[i]] = i
            N = i - l + 1
            ans += (N * (N + 1)) // 2
        print(ans)
 
if __name__ == "__main__":
    main()
