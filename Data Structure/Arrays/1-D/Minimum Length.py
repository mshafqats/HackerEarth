'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

t = int(input())

for _ in range(t):
    num = int(input())
    list1 = input().split(" ")
    list2 = input().split(" ")
    diff_indices = [i for i in range(num) if list1[i] != list2[i]]
    if not diff_indices:
        print(0)
    else:
        print(max(diff_indices) - min(diff_indices) + 1)