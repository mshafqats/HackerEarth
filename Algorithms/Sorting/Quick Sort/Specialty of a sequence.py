'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def calculate_sum(n, k, values):
    values.sort()
    result = sum(values[:n - k])
    return result
 
n, k = map(int, input().split())
a = list(map(int, input().split()))
 
output = calculate_sum(n, k, a)
print(output)
