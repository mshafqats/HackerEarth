'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def solve (A, U, N):
    l = []
    al = A[0]
    ul = U[0]
    for i in range(1, N):
        if ul == U[i]:
            al = max(al, A[i])
        else:
            l.append(al)
            al = A[i]
            ul = U[i]
    l.append(al)
    return sum(l)
 
T = int(input())
for _ in range(T):
    N = int(input())
    U = list(map(int, input().split()))
    A = list(map(int, input().split()))
    out_ = solve(A, U, N)
    print (out_)
