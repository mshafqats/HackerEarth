'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

n = int(input())
quantity = list(map(int,input().split()))
Q = int(input())
queries = [int(input()) for i in range(Q)]
quantity.sort()
def store():
    hmap = {}
    sumUpto = 0
    for i in range(n):
        val = sumUpto + quantity[i] * (n-i)
        hmap[i] = val
        sumUpto += quantity[i]
    hmap[n] = sumUpto
    return hmap
def storeSum():
    hmapSum = {}
    sumUpto = 0
    for i in range(n):
        hmapSum[i] = sumUpto
        sumUpto += quantity[i]
    return hmapSum
hmap = store()
hmapSum = storeSum()
def getMin(k):
    start = 0
    end = n-1
    index = n
    while start <= end:
        mid = (start + end)//2
        if hmap[mid] < k:
            start = mid + 1
        elif hmap[mid] >  k:
            index = mid
            end = mid - 1
        else:
            index = mid
            break
    if index == n:
        return -1
    elif index == 0:
        if k % n == 0:
            return k // n
        else:
            return (k // n) + 1
    else:
        if (k-hmapSum[index]) % (n-index) == 0:
            return (k - hmapSum[index]) // (n -index)
        else:
            return (k-hmapSum[index]) // (n-index) +  1
 
for i in queries:
    print(getMin(i))
