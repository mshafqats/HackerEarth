'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def solve(l,m,n):
    ans=0
    for i in range(m):
        t,g,v=map(int,input().split())
        l[t-1]+=v
        l[g-1]-=v
    for i in range(n):
        if l[i]>0:
            ans+=l[i]
    print(ans)
 
def main():
    n,m=map(int,input().split())
    l=[0]*n
    solve(l,m,n)
    
if __name__=="__main__":
    main()
