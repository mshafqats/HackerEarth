'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

N=int(input())
sayi=input()
sayi=sayi.split()
c=1
for i in range(N-1):
    if sayi[i]==sayi[i+1]:
        c+=1
print(N-c+1)
