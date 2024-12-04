'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def nthPerm(perm, div, lngth, n):
    rtrnList = []
    x = 0
    i = lngth - 3
    while n < div[i]:
        x += 1
        i -= 1
    if x != 0:
        if n == div[i]:
            return perm[:x+1] + perm[lngth:x:-1]
        else:
            rtrnList.extend(perm[:x])
            del perm[:x]
    for d in div[i::-1]:
        x = n % d
        if x == 0:
            #n = int(n/d)
            n = n // d
            rtrnList.append(perm[n - 1])
            del perm[n - 1]
            return rtrnList + perm[::-1]
        #n = int((n - x) / d)
        n = n // d
        rtrnList.append(perm[n])
        del perm[n]
        n = x
    return rtrnList + perm
 
def nthRepPerm(perm, div, lngth, uniqCnt, n):
    rtrnList = []
    repFrwd = [0] * lngth
    repRvrs = [0] * lngth
    repMult = 1
 
    for i in range(lngth - 2, -1, -1):
        if perm[i] == perm[i + 1]:
            repRvrs[i] = repRvrs[i + 1] + 1
    for i in range(1, lngth):
        if perm[i - 1] == perm[i]:
            repFrwd[i] = repFrwd[i - 1] + 1
            repMult *= (repRvrs[i - 1] + 1)
 
    for i in range(len(div)):
        a = div[i] / repMult
        y = int(n / a)
        if n % a == 0:
            y -= 1
        y = y-repFrwd[y]
        rtrnList.append(perm[y])
        del perm[y]
        n = n - int(a * y)
        lngth = lngth - 1
        if repRvrs[y] == 0:
            uniqCnt -= 1
        repMult = repMult // (repRvrs[y]+1)
        if repMult == 1:
            if n == 1:
                return rtrnList + perm
            return rtrnList + nthPerm(perm,div[:i:-1],lngth,n)
        del repFrwd[y+repRvrs[y]]
        del repRvrs[y]
        if uniqCnt == 2 and repMult == div[i] // lngth:
            if repRvrs[0] == 0:
                perm[0], perm[n-1] = perm[n-1], perm[0]
            else:
                perm[-1],perm[-n] = perm[-n], perm[-1]
            return rtrnList + perm
 
    return rtrnList + perm
 
def calNthPerm():
    div = [1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000, 2432902008176640000]
    for _ in range(int(input())):
        abc, n = input().split()
        n = int(n)
        lngth = len(abc)
        abc = [i for i in abc]
        abc.sort()
        if n == 1:
            print(*abc,sep="")
            continue
        if n >= div[lngth - 1]:
            print(*abc[::-1],sep="")
            continue
        uniqCnt = len(set(abc))
        if uniqCnt != lngth:
            #for _ in range(n-1):
                #abc = myPerm(abc,lngth)
            abc = nthRepPerm(abc,div[lngth-2:0:-1],lngth,uniqCnt,n)
            print(*abc,sep="")
        else:
            abc = nthPerm(abc,div[1:lngth-1],lngth,n)
            print(*abc,sep="")
 
calNthPerm()
