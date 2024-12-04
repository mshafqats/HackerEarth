'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

Mod = 1000000007
p = [1] * 200200
for x in range(1, len(p)):
  p[x] = p[x - 1] * x % Mod
for _ in range(int(input())):
  n = int(input())
  s = 0
  v = 1
  for x in map(int, input().split()):
    y = abs(x)
    s += y
    v = v * p[y] % Mod
  print(p[s] * pow(v, Mod - 2, Mod) % Mod)
