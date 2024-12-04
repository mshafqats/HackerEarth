'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def Find_K(K, Score, N):
    points = [0] + Score
    return sorted(range(len(points)), key=lambda x: points[x], reverse=True)[:K]
 
N, K = map(int, input().split())
Score = list(map(int, input().split()))
out_ = Find_K(K, Score, N)
print(' '.join(map(str, out_)))
