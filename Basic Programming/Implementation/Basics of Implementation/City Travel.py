'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

import math

if __name__ == "__main__": 
   S,X,N = map(int,input().split()) 
   days = 0 
   distance = S 
   TY = [] 
   defDays = math.ceil(S/X) 
   for i in range(N): 
       TY.append(list(map(int,input().split()))) 
    
   TY.sort() 
   i = 0 
   pas = 0 
   while distance > 0: 
       if i <N: 
           if TY[i][0]-1 == days: 
               distance -= TY[i][1] 
               days += 1 
               i += 1 
           else: 
               Ti = TY[i][0] 
               Tj = TY[i-1][0]+1 if i>0 else 1 
               yGap = (Ti - Tj)*X 
               if yGap<distance: 
                   distance -= yGap 
                   days += yGap//X 
               else: 
                   i=N 
       else: 
           days += math.ceil(distance/X) 
           distance -= X*math.ceil(distance/X) 
   print(days)
