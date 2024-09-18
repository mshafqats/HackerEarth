'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

s=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'] 
a=list(raw_input())
b=list(raw_input())
a.extend(b)
k=0
t=[]
for i in s:
	if a.count(i)%2==0:
		k+=a.count(i)
	else:
		t.append(a.count(i)) 
p=max(t) 
k+=p
t.remove(p)
for i in t:
	if i>1:
		k+=i-1
print k
