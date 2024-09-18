'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def process_case(n, a):
    i = 1
    last = (1 << 25) - 1
    p = {d: n for d in range(25)}
    
    for v in reversed(a[1:]):
        nou_last = last & v
        if nou_last != last:
            b = bin(last - nou_last)
            for d, bit in enumerate(b[:1:-1]):
                if bit == '1':
                    p[d] = i
            last = nou_last
            if last == 0:
                break
        i += 1
    
    value = sum(v * (1 << k) for k, v in p.items())
    ans = -((1 << 25) - 1) + value
    primer = (1 << 25) - 1
    i = n - 1
    canvis = set(p.values())
    canvis.update([0, n - 1])
    
    for v in a:
        nou_primer = primer & v
        if nou_primer != primer:
            b = bin(primer - nou_primer)
            for d, bit in enumerate(b[:1:-1]):
                if bit == '1':
                    value -= p[d] * (1 << d)
                    p[d] = 0
            primer = nou_primer
            if primer == 0:
                break
        if i in canvis:
            loss = 0
            for k, v in p.items():
                if i < v:
                    loss += (1 << k)
        value -= loss
        ans += value
        i -= 1
    
    return ans
 
def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    T = int(data[index])
    index += 1
    results = []
    
    for _ in range(T):
        n = int(data[index])
        index += 1
        a = list(map(int, data[index:index + n]))
        index += n
        result = process_case(n, a)
        results.append(result)
    
    for result in results:
        print(result)
 
if __name__ == "__main__":
    main()
