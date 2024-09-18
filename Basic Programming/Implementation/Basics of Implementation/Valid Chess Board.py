'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

n, m = map(int, input().split())
mat = []
for i in range(n):
    row = [int(x) for x in input()]
    mat.append(row)
dp = [[1 for y in range(m)] for x in range(n)]
res = 0
for r in range(1, n):
    for c in range(1, m):
        if (mat[r][c] != mat[r-1][c]) and (mat[r][c] != mat[r][c-1]) and (mat[r][c] == mat[r-1][c-1]):
            dp[r][c] = 1 + min(dp[r-1][c], dp[r][c-1], dp[r-1][c-1])
        if dp[r][c] >= 8:
            res += 1
print(res)
