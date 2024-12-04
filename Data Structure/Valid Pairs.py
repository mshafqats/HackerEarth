'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def solve(N, wealth):
    import math
    powers_of_3 = set()
    k = 0
    while 3 ** k <= 2 * max(wealth):
        powers_of_3.add(3 ** k)
        k += 1
    wealth_count = {}
    for w in wealth:
        if w in wealth_count:
            wealth_count[w] += 1
        else:
            wealth_count[w] = 1
    valid_pairs = 0
    for w in wealth:
        wealth_count[w] -= 1
        for p in powers_of_3:
            complement = p - w
            if complement in wealth_count and wealth_count[complement] > 0:
                valid_pairs += wealth_count[complement]
    return valid_pairs

N = input()
wealth = map(int, raw_input().split()) 
out_ = solve(N, wealth)
print out_
