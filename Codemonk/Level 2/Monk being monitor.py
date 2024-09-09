'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

for _ in range(input()):
  n = input()
  arr = map(int, input().split())
  arr.sort()
  res = 0
  min = "_"
  current_freq = 0
  for i in range(n):
    if i!=n-1 and arr[i] == arr[i+1]:
      current_freq += 1
    else:
      current_freq += 1
      if min == "_":
        min = current_freq
      else:
        if min > current_freq:
          min = current_freq
        else:
          res = max(res, current_freq-min)
        
        current_freq = 0
  if res > 0:
    print(res)
  else:
    print("-1")