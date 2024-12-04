'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

RI = lambda: map(int, raw_input().split())
M = 1000000007
N = 200200
p = [1] * N
for x in xrange(1, N):
    p[x] = p[x - 1] * x % M
 
for _ in xrange(input()):
    x1, y1, x2, y2, k = RI()
    dx = abs(x1 - x2)
    dy = abs(y1 - y2)
    if dx + dy > k:
        print 0
        continue
    if (dx + dy) % 2 != k % 2:
        print 0
        continue
    x = dx
    ans = 0
    while x <= k:
        y = k - x
        if y < dy:
            break
        t = p[x] * pow(p[(x + dx) / 2], M - 2, M) % M * pow(p[(x - dx) / 2], M - 2, M) % M
        t *= p[y] * pow(p[(y + dy) / 2], M - 2, M) % M * pow(p[(y - dy) / 2], M - 2, M) % M
        ans += t % M * p[k] % M * pow(p[x], M - 2, M) % M * pow(p[y], M - 2, M) % M
        x += 2
    print ans % M
