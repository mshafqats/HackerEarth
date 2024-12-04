'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

class TrieNode:
    def __init__(self):
        self.d = {}
        self.is_end_of_string = False
        self.add = -1
class Trie:
    def __init__(self):
        self.root = TrieNode()
    def insert(self,key):
        pCrawl = self.root
        for level in range(len(key)):
            if key[level] not in pCrawl.d:
                pCrawl.d[key[level]] = [TrieNode(),key[level]]
            pCrawl = pCrawl.d[key[level]][0]
        pCrawl.is_end_of_string = True
    def wholeword_search(self,key):
        pCrawl = self.root
        for level in range(len(key)):
            if key[level] not in pCrawl.d:
                return False
            pCrawl = pCrawl.d[key[level]][0]
        return pCrawl.is_end_of_string
def display(TrieNode,a,string):
        if TrieNode.is_end_of_string == True:
            string.append("".join(a))
        temp = list(a)
        for i in TrieNode.d:
            a.append(TrieNode.d[i][1])
            display(TrieNode.d[i][0],a,string)
            a = list(temp)
        return string
t = Trie()
n = int(input())
for i in range(n):
    s = input()
    if t.wholeword_search(s)==False:
        t.insert(s)
        print(s)
    else:
        pCrawl = t.root
        for level in range(len(s)):
            pCrawl = pCrawl.d[s[level]][0]
        while True:
            pCrawl.add += 1
            if t.wholeword_search(s+str(pCrawl.add))==False:
                print(s+str(pCrawl.add))
                t.insert(s+str(pCrawl.add))
                break
