'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

n,c,m=int(input()),[],[]
for _ in range(n):
    s,v=raw_input().split()
    if(s=='Coin'):
        c.append(int(v))
    else:
        m.append(int(v))
print('Coins :')
for k in c:
    print(k)
print('Notes :')
for k in m:
    print(k)
