'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

input()
M = 10**9 + 7
ans = 0
for v in map(int, input().split()):
    ans = (ans + (1 + ans) * v) % M
print(ans)
