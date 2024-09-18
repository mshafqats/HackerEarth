'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

import math
def solve (k, n):
    # Write your code here
    pre=0
    ret=0
    num=1
    val=1
    while(1):
        num=num*k
        if(num>n):
            ret += (n-pre+1)*val
            break
        ret+=(num-pre)*val
        pre=num
        val+=1
    return ret
 
T = int(input())
for _ in range(T):
    n,k = map(int,input().split())
 
    out_ = solve(k, n)
    print (out_)
    print('\n')
