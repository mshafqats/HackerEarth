'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

T=int(input())
for i in range(T):
    m,n=map(int,input().split())
    h1=list(map(int,input().split()))
    h2=list(map(int,input().split()))
    f=0
    h1.sort()
    h2.sort()
    if(len(h1)<=len(h2)):
        for i in range(0,len(h1)):
            if h1[i]>h2[i]:
                f=1
            else:
                f=0
                break
    else:
        for i in range(0,len(h2)):
            if h1[i]>h2[i]:
                f=1
            else:
                f=0
                break
    if f==1:
        print("YES")
    else:
        print("NO")
