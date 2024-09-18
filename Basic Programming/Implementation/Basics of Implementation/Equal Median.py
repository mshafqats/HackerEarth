'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def findswap():
    if a[m] == med:
        if b[m] > med:
            i = m
            count = 0
            while i > -1 and b[i] > med:
                count += 1
                i -= 1
            return count
        elif b[m] < med:
            i = m
            count = 0
            while i < n and b[i] < med:
                count += 1
                i += 1
            return count
    elif b[m] == med:
        if a[m] > med:
            i = m
            count = 0
            while i > -1 and a[i] > med:
                count += 1
                i -= 1
            return count
        elif a[m] < med:
            i = m
            count = 0
            while i < n and a[i] < med:
                count += 1
                i += 1
            return count
    else:
        if a[m] > med:
            i = m
            while i > -1 and a[i] > med:
                i -= 1
            d1 = m - i
            j = m
            while j < n and b[j] < med:
                j += 1
            d2 = j - m
            return max(d1, d2)
        else:
            i = m
            while i < n and a[i] < med:
                i += 1
            d1 = i - m
            j = m
            while j > -1 and b[j] > med:
                j -= 1
            d2 = m - j
            return max(d1, d2)
 
if __name__ == '__main__':
    t = int(input())                
    for i in range(t):
        n = int(input())
        m = n // 2
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        a = sorted(a)
        b = sorted(b)
        if a[m] == b[m]:
            print(0)
            continue
        c = a + b
        c = sorted(c)
        if c[n - 1] != c[n]:
            print (-1)
            continue
        med = c[n]
        print(findswap ())
