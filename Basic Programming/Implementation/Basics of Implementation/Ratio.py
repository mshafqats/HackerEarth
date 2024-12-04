'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

from math import gcd
from sys import stdin
def solve():
    results = []
    for _ in range(int(stdin.readline())):
        N = int(stdin.readline())
        K, C = stdin.readline().split()
        K = int(K)
        arr = [K,]
        first = C
        prev = C
        counts = {"A":0, "B":0}
        counts[C] = K
        for _ in range(N - 1):
            K, C = stdin.readline().split()
            K = int(K)
            counts[C] += K
            if prev == C:
                arr[-1] += K
            else:
                arr.append(K)
            prev = C
        if len(arr) == 1:
            results.append(arr[0])
            continue
        x = gcd(counts["A"], counts["B"])
        if x == 1:
            results.append(1)
            continue
        counts["A"] //= x
        counts["B"] //= x
        if first == "B":
            counts["A"], counts["B"] = counts["B"], counts["A"]
        ans = 0
        n = len(arr)
        splitA, splitB = 0, 0
        for i in range(n - 1):
            if arr[i] == 0:
                continue
            if i % 2 == 0:
                neededA = arr[i+1] * counts["A"] // counts["B"]
                neededB = arr[i] * counts["B"] // counts["A"]
                if arr[i] % counts["A"] == 0 and arr[i+1] >= neededB:
                    if arr[i+1] > neededB and splitB > neededB:
                        arr[i+2] += arr[i]
                        splitA += arr[i]
                        splitB = 0
                        arr[i] = 0
                        continue
                    arr[i] = 0
                    arr[i+1] -= neededB
                    ans += 1
                    splitA, splitB = 0, 0
                else:
                    try:
                        arr[i+2] += arr[i]
                        splitA += arr[i]
                        arr[i] = 0
                        splitB = 0
                    except:
                        break
            else:
                neededB = arr[i+1] * counts["B"] // counts["A"]
                neededA = arr[i] * counts["A"] // counts["B"]
                if arr[i] % counts["B"] == 0 and arr[i+1] >= neededA:
                    if arr[i+1] > neededA and splitA > neededA:
                        try:
                            arr[i+2] += arr[i]
                            splitB += arr[i]
                            splitA = 0
                            arr[i] = 0
                            continue
                        except:
                            break
                    arr[i] = 0
                    arr[i+1] -= neededA
                    ans += 1
                    splitA, splitB = 0, 0
                else:
                    try:
                        arr[i+2] += arr[i]
                        splitB += arr[i]
                        arr[i] = 0
                        splitA = 0
                    except:
                        break
        if ans == 0:
            ans = 1
        results.append(ans if arr[-1] == 0 else 1)
    print ('\n'.join(str(k) for k in results))
solve()
