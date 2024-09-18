'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def main():
    def us_altab(a, b):
        sonuc = 1
        while b:
            if b & 1:
                sonuc *= a
                sonuc %= modulo
            a *= a
            a %= modulo
            b >>= 1
        return sonuc
 
    def ters_euler(n):
        return us_altab(n, modulo - 2)
 
    def kombinasyon(n, r):
        return (faktoriyel[n] * ((iteratif_ters_faktoriyel[r] * iteratif_ters_faktoriyel[n - r]) % modulo)) % modulo
 
    N, K, X = map(int, input().split())
    dizi = sorted(map(int, input().split()))
    modulo = 10**9 + 7
    faktoriyel = [1] * N
    iteratif_ters_faktoriyel = [1] * N
    for i in range(1, N):
        faktoriyel[i] = (i * faktoriyel[i - 1]) % modulo
    iteratif_ters_faktoriyel[-1] = ters_euler(faktoriyel[-1])
    for i in range(N - 2, -1, -1):
        iteratif_ters_faktoriyel[i] = (iteratif_ters_faktoriyel[i + 1] * (i + 1)) % modulo
    isaretci = sayac = sonuc = 0
    while isaretci < N:
        while sayac < N and (dizi[sayac] - dizi[isaretci]) <= X:
            sayac += 1
        sayac -= 1
        if sayac - isaretci >= K - 1:
            sonuc = (sonuc + kombinasyon(sayac - isaretci, K - 1)) % modulo
        isaretci += 1
    print(sonuc)
 
if __name__ == "__main__":
    main()
