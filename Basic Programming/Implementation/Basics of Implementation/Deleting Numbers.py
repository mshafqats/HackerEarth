'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

n,k=map(int,input().split())
A=[0]+[int(x) for x in input().split()]
middle=(n+1)//2
N=n-k
Middle=(N+1)//2
End=Middle+k
a=A[Middle:End+1]
print(max(a))
