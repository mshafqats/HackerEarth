'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

import sys
 
def main():
   n, m = map(int, sys.stdin.readline().split())
   a = list(map(int, sys.stdin.readline().split()))
   ma = {}
   for num in a:
       ma[num % m] = ma.get(num % m, 0) + 1
   max_m = -1
   max_s = 0
   for key, value in ma.items():
       if value > max_s:
           max_s = value
   ans = []
   a.sort()
   for num in a:
       if max_m == -1:
           if ma[num % m] == max_s:
               ans.append(num)
               max_m = num % m
       elif num % m == max_m:
           ans.append(num)
   print(len(ans))
   print(*ans)
 
if __name__ == "__main__":
   main()
