'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def lex(arr):
    for i in range(1, len(arr)):
        if "".join(arr[i - 1]) > "".join(arr[i]):
            return False
    return True
 
n, m = map(int, input().split())
arr = [input() for _ in range(n)]
count = 0
temp = [[] for _ in range(n)]
 
for j in range(m):
    for i in range(n):
        temp[i].append(arr[i][j])
    if not lex(temp):
        for s in temp:
            s.pop()
 
print(m - len(temp[0]))
