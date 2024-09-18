'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

s=input()
list_1=list(set(s))
c=len(s)
s1=""
list_=[]
for i in list_1:
    list_.append(s.replace(i,''))
list_.sort()
print(list_[0])