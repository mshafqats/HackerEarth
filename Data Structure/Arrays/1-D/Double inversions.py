'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def din(l1,l2,n):
    a=[n-l1[i]-l2[n-i-1] for i in range(n)]
    if len(set(a))==n and min(a)==1 and max(a)==n:
        return " ".join(map(str,a))
    else:
        return-1
if __name__=='__main__':
    for _ in range(int(input())):
        n=int(input())
        l1=list(map(int,input().split()))
        l2=list(map(int,input().split()))
        print(din(l1,l2,n))
