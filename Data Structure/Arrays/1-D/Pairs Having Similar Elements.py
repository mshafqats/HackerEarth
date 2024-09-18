'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def SimilarElementsPairs (A,N):
    sorted_list = sorted(A)
    similar = False
    ans = 0
    count = 0
    prev = sorted_list[0]
    for elem in sorted_list:
        if elem == prev:
            count += 1  
        elif prev+1 == elem:
            count += 1
            similar = True
        else:
            if similar:
                ans += (count * (count-1)) // 2
                similar = False
            count = 1
        prev = elem
    if similar:
                ans += (count * (count-1)) // 2
    return ans
    
N = int(input())
A = map(int,input().split())
out_ = SimilarElementsPairs(A,N)
print(out_)
