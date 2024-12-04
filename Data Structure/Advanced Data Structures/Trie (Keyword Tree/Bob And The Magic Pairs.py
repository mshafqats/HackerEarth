'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

from sys import stdin
from collections import defaultdict
 
def lmap(function, iterable): return list(map(function, iterable))
def line(): return stdin.readline().strip()
def rd(converter): return converter(line())
def rl(converter, delimeter = None): return lmap(converter, line().split(delimeter))
def rls(num_lines, converter): return [rd(converter) for i in range(num_lines)]
def rg(num_lines, converter, delimeter = None): return [rl(converter,delimeter) for i in range(num_lines)]
 
MULTIPLE_CASES = 1
 
class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.total = 0
 
class Trie:
    def __init__(self):
        self.dict1 = TrieNode()
    
    def insert(self, num):
        dict2 = self.dict1
        
        for i in range(15,-1,-1):
            bit = (num >> i) & 1
            dict2.children[bit].total += 1
            dict2 = dict2.children[bit]
    
    def count(self, val, high):
        res, dict2 = 0, self.dict1
    
        for i in range(15,-1,-1):
            if not dict2:
                break
                
            bit = (val >> i) & 1
            temp = (high >> i) & 1
            
            if temp:
                res += dict2.children[bit].total
                dict2 = dict2.children[1 - bit]
            else:
                dict2 = dict2.children[bit]
                
        return res
 
def main():
    n,u,v = rl(int)
    ns = rl(int)
 
    trie, total = Trie(), 0
    
    for num in ns:
        total += trie.count(num,v+1)-trie.count(num,u)
        trie.insert(num)
    
    print(total)
 
for i in range(rd(int) if MULTIPLE_CASES else 1): main()
