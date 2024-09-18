'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

MOD=1000000007
 
fact=[]
factinv=[]
ans=[]
 
def ncr(n,r):
    ans=1
    ans=(ans*fact[n])%MOD
    ans=(ans*factinv[r])%MOD
    ans=(ans*factinv[n-r])%MOD
    return ans
 
def binExpo(x,y):
    ans=1
    while y>0:
        if y%2==1:
            ans=(ans*x)%MOD
        x=(x*x)%MOD
        y=y//2
    return ans
 
def searchless(low,high,val,a):
    mid=(low+high)//2
    if a[mid]<val and a[mid+1]>=val:
        return mid
    elif a[mid]<val:
        return searchless(mid+1,high,val,a)
    else:
        return searchless(low,mid,val,a)
 
n,q=input().split()
n=int(n)
q=int(q)
a=list(map(int, input().split()))
a.append(0)
a.append(1000000001)
a.sort()
fact.append(1)
factinv.append(1)
i=1
while i<=n:
    fact.append((i*fact[i-1])%MOD)
    factinv.append((factinv[i-1]*binExpo(i,MOD-2))%MOD)
    i+=1
i=0
while i<=n-1:
    ans.append(ncr(n-1,i))
    if i>0:
        ans[i]=(ans[i]+ans[i-1])%MOD
    i+=1
b=list(map(int, input().split()))
for i in b:
    x=searchless(0,n+1,i,a)
    y=n+1-(x+2)
    #print(x,y)
 
    print(ans[x])
