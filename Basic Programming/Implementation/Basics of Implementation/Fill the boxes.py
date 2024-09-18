'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

t = int(input())
for _ in range(t):
    n, m, k = map(int, input().split())
    box = list(map(int, input().split()))
    balls = list(map(int, input().split()))
    box.sort(reverse = True)
    balls.sort(reverse = True)
    i = 0
    j = 0
    ans = 0
    while i < m and j < n:
        if balls[i] <= (box[j] + k) and balls[i] >= box[j]:
            i += 1
            j += 1
            ans += 1
        elif balls[i] < box[j]:
            j += 1
        else:
            i += 1
    print(ans)
