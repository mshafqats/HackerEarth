'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

from bisect import bisect_left
p=10**9+7
def solve(arr,n,k,m):
    sum1=[0]
    for x in arr:
        sum1.append(x+sum1[-1])
    total=sum1[-1]
    cops,rem=divmod(k,total)
    if cops>=m:
        p=m*n
        return p*(p+1)//2
    res=0
    for j in range(1,len(sum1)):
        sumj=sum1[j]
        cp=cops
        if rem>=sumj:
            cp+=1
        if cp>0:
            add=cp*(j*2+(cp-1)*n)/2
            res+=int(add)
        i=bisect_left(sum1,cp*total+sumj-k)
        res+=(m-cp)*(cp*n+j-i)
    return res
t=int(input())
while(t):
    n,m,k=map(int,input().split())
    s=list(map(int,input().split()))
    print(solve(s,n,k,m)%p)
    t-=1
