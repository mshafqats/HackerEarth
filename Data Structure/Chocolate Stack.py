'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def solution (n, c):
    stack=[]
    ans=[]
    for i in c:
        if i==0:
            x=stack.pop()
            ans.append(x)
        else:
            stack.append(i)
    return ans
N = int(input())
C = list(map(int, input().split()))
 
out_ = solution(N, C)
print (' '.join(map(str, out_)))
