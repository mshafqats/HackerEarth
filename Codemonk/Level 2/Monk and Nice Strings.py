'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

n = input()
s = []
for i in range(n):
    s.append(input())
    count = 0
    for j in range(i):
      if s[j] < s[i]:
        count += 1
    print(count)