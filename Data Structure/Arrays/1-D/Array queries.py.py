'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def array_queries (N, M, A, B, Q, queries):
    # Write your code here
    s1 = sum(B)
    s2 = sum((j + 1) * B[j] for j in range(M))
    s3 = sum((i + 1) * A[i] for i in range(N))
    s4 = sum(A)
 
    F = lambda: (s1 * s3 + s2 * s4) % 998244353
 
    res = [F()]
    for op, i, j in queries:
        i -= 1
        j -= 1
        if op == 1:
            s1 += (A[i] - B[j])
            s2 += ((j + 1) * (A[i] - B[j]))
            s3 += ((i + 1) * (B[j] - A[i]))
            s4 += (B[j] - A[i])
            A[i], B[j] = B[j], A[i]
        elif op == 2:
            s3 += (i - j) * (A[j] - A[i])
            A[i], A[j] = A[j], A[i]
        else:
            s2 += (i - j) * (B[j] - B[i])
            B[i], B[j] = B[j], B[i]
        res.append(F())
    return res
    
 
T = int(input())
for _ in range(T):
    N = int(input())
    M = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    Q = int(input())
    queries = [list(map(int, input().split())) for i in range(Q)]
 
    out_ = array_queries(N, M, A, B, Q, queries)
    print (' '.join(map(str, out_)))
