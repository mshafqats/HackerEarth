'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        slide = input().strip()
        k = slide.count('K')
        countK = maxK = slide[:k].count('K')
        slide += slide
        for i in range(k, k + N):
            countK = countK + (1 if slide[i] == 'K' else 0) - (1 if slide[i - k] == 'K' else 0)
            maxK = max(maxK, countK)
        print(k - maxK)
 
if __name__ == "__main__":
    main()
