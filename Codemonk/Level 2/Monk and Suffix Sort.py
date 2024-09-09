'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

s, n = map(str, input().split())
n = int(n)
arr = []
for i in range(len(s)):
  arr.append(s)
  s = s[1:]

arr.sort()
print(arr[n-1])