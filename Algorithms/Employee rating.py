'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def solve (N, workload):
    currentDays = 0
    maxDays = 0
    for i in workload:
        if(i>6):
            currentDays+=1
            if(currentDays>maxDays):
                maxDays=currentDays
        else:
            currentDays=0
    return maxDays
 
N = int(input())
workload = list(map(int, input().split()))
 
out_ = solve(N, workload)
print (out_)
