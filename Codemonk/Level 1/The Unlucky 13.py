'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

cache = {}
mod = 1000000009

def ans(n):
  if n < 50000000:
    if n in cache:
      return cache[n]

    if n == 0:
      cache[n] = 1
      return cache[n]
    
    if n == 1:
      cache[n] = 10
      return cache[n]
    
    x = ans(n//2)
    y = ans(n//2-1)
    if (n % 2) == 0:
      cache[n] = (x*x - y*y) % mod
    else:
      z = ans(n//2+1)
      cache[n] = (x * (z - y)) % mod
    return cache[n]
  else:
    if n in cache2:
      return cache2[n]
    
    temp1 = ans(n//2)
    temp2 = ans(n//2-1)

    if (n % 2) == 0:
      cache2[n] = (temp1 * temp1 - temp2 *temp2) % mod
    else:
      temp3 = ans(n//2+1)
      cache2[n] = (temp1 * (temp3 - temp2)) % mod
    return cache2[n]

inp_len = int(input())

for i in range(inp_len):
  n = int(input())
  cache2 = {}
  print(ans(n))