'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def solve():
 
	s = raw_input()
	seen = [False] * len(s)
	mapper = {}
 
	for i, j in enumerate(s):
		if j in mapper:
			mapper[j].append(i)
		else:
			mapper[j] = [i]
 
	q = input()
 
	for i in xrange(q):
		k, c = raw_input().split()
		k = int(k)
		seen[mapper[c][k-1]] = True
		del mapper[c][k-1]
 
 
	print "".join(j for i, j in enumerate(s) if not seen[i])
 
solve()
