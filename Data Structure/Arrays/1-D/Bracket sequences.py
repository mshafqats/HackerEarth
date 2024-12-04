'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def solve(s):
    p=0
    t=0
    res = 0
    for i in s:
        if(i=='('):
            p+=1
        else:
            p-=1;
        if (p<t):
            t=p
            res = 0
        if(t==p):
            res+=1
    if p:
        return 0
    else:
        return res
s= input()
print(solve(s))
