'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

from sys import stdin
input = stdin.readline
 
MODULO = 10 ** 9 + 7
ALPHABET = 2
 
class TrieNode:
    __slots__ = ['children']
    def __init__(self):
        self.children = [None] * ALPHABET
 
class Trie:
    __slots__ = ['root']
    def __init__(self):
        self.root = TrieNode()
 
    def insert(self, key):
        present = [False] * len(key)
        pCrawl = self.root
        for level in range(len(key)):
            index = ord(key[level]) - ord('a')
            if not pCrawl.children[index]:
                pCrawl.children[index] = TrieNode()
            else:
                present[level] = True
            pCrawl = pCrawl.children[index]
        return present
 
def countbeautiful(S, seen):
    present = seen.insert(S)
    if present[len(S) - 1]:
        return 0
    total = 0
    count = 0
    dcount1, dcount2, dcount3 = 0, 0, 0
    C1, C2, C3 = 'a', 'a', S[0]
    for i in range(1, len(S)):
        if S[i] == 'a':
            if C3 != 'a':
                dcount1, dcount2, dcount3 = dcount2, dcount3, 0
                C1, C2, C3 = C2, C3, 'a'
        else:
            C1, C2, C3 = C2, C3, 'b'
            if C2 == 'a':
                if C1 == 'b':
                    dcount1, dcount2, dcount3 = dcount2, dcount3, 1 + dcount1
            else:
                dcount1, dcount2, dcount3 = dcount2, dcount3, 1 + dcount2
        count += dcount3
        if not present[i]:
            total += count
    return total
 
def solve(S):
    seen = Trie()
    total = 0
    for Si in S:
        total = (total + countbeautiful(Si, seen)) % MODULO
    return total
 
if __name__ == "__main__":
    N = int(input().strip())
    S = []
    for i in range(N):
        Si = input().strip()
        S.append(Si)
    S = sorted(S, key = lambda x: len(x), reverse = True)
    print(solve(S))
