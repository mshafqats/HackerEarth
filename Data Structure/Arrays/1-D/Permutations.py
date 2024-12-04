'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

from math import ceil,gcd,factorial,sqrt,log,log2
import queue
import heapq as hq
from itertools import permutations,combinations,accumulate,product
from collections import Counter,deque
from sys import stdin,stdout
from bisect import bisect,insort,bisect_left,insort_left
input=stdin.readline

def sieve(n):
    prime = [True]*(n+1)
    p = 2
    prime[0]=False
    prime[1]=False
    for p in range(2,int(n**0.5)+1):
        if (prime[p] == True):
            for l1 in range(p * p, n+1, p):
                prime[l1] = False
    return prime
def simplesieve(n):
    prime=[2]
    mak=[False]*(n+1)
    for p in range(3,n+1,2):
        if(mak[p]==False):
            prime.append(p)
            if(p*p<=n):
                for l1 in range(p*p,n +1,2*p):
                    mak[l1]=True
    return prime
def segementedsieve(low,high):
    primes=simplesieve(int(high**.5))
    prime = [True] * (high-low + 1)
    for i in primes:
        lower = (low//i)*i
        if lower<low:
            lower+=i
        for j in range(lower,high+1,i):
            if(j!=i):
                prime[j-low]=False
    ans=[]
    for i in range(low,high+1):
        if prime[i-low]:
            ans.append(i)
    return ans
def isprime(n):
    if(n==2):
        return True
    if(n%2==0 or n==1):
        return False
    for l1 in range(3,int(n**0.5)+1,2):
        if(n%l1==0):
            return False
    return True

def binpow(a,b,m):
    r2=1
    a=a%m
    while(b>0):
        if(b&1):
            r2=(r2*a)%m
        a=(a*a)%m
        b>>=1
    return r2
def lcm(a,b):
    return (a//gcd(a,b))*b

def gcdExtended(a,b): 
    if(b==0):  
        return a,1,0
    g,x1,y1=gcdExtended(b,a%b)  
    x1,y1 = y1,x1-(a//b)*y1 
    return g,x1,y1
def binseach(a,l,r,key):
    while(r-l>1):
        m=l+(r-l)//2
        if(a[m]<=key):
            l=m
        else:
            r=m
    if(a[l]==key):
        return l
    if(a[r]==key):
        return r
    return -1
class Node():
    def init(self, data):
        self.data = data
        self.left = None
        self.right = None
def inorder(root):
    res, stack = [], []
    current = root
    while True:
        while current:
            stack.append(current)
            current = current.left
        if len(stack) == 0:
            return res
        node = stack[-1]
        stack.pop(len(stack)-1)
        if node.data != None:
            res.append(node.data)
        current = node.right
    return res 
 
def dfs(graph,s,v,ans):
    v[s]=1
    ans.append(s)
    for i in graph[s]:
        if(v[i]==0):
            dfs(graph,i,v,ans)
def bfs(graph,n,x,dest):
    v=[0]*(1+n)
    d=[0]*(1+n)
    d[x]=0
    v[x]=1
    q=queue.Queue()
    q.put(x)
    while(not q.empty()):
        z=q.get()
        for s in graph[z]:
            if(v[s]==0):
                v[s]=1
                d[s]=d[z]+1
                q.put(s)
    return d[dest] 
n,q=map(int,input().split())
a=list(map(int,input().split()))
pre=[a[0]]
for i in range(1,n):
    pre.append(max(pre[i-1],a[i])) 
suf=[a[-1]]
for i in range(n-2,-1,-1):
    suf.append(max(suf[n-2-i],a[i])) 
suf.reverse()
for _ in range(q):
    l,r=map(int,input().split())
    if(l==1):
        m=suf[r]
    elif(r==n):
        m=pre[l-2]
    else:
        m=max(pre[l-2],suf[r])
    print(m)
