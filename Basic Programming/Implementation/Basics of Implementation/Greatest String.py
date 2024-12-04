'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def lexicographically_greatest_string(s, q):
    vowels = 'aeiou'
    s = list(s)
    for i in range(len(s)):
        if s[i] in vowels and q > 0:
            s[i] = chr(ord(s[i]) + 1)
            q -= 1
    return ''.join(s)
 
t = int(input())
for _ in range(t):
    s = input()
    q = int(input())
    print(lexicographically_greatest_string(s, q))
