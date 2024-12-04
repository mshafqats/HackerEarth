'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def check_s_t(s: str, t: str):
    idx = []
    for i in range(len(s)):
        if s[i] != t[i]:
            idx.append(i)
            if len(idx) > 3:
                return "NO"
    if len(idx) == 0:
        return "YES"
 
    if len(idx) == 1:
        return "YES"
 
    char_set = set()
    if len(idx) == 2:
        char_set.add(s[idx[0]])
        char_set.add(t[idx[0]])
        char_set.add(s[idx[1]])
        char_set.add(t[idx[1]])
 
        if (len(char_set) == 2) or (len(char_set) == 3):
            return "YES"
        else:
            return "NO"
 
    if len(idx) == 3:
        lst = []
        char_set.add(s[idx[0]])
        char_set.add(t[idx[0]])
        char_set.add(s[idx[1]])
        char_set.add(t[idx[1]])
        char_set.add(s[idx[2]])
        char_set.add(t[idx[2]])
 
        lst.append(s[idx[0]])
        lst.append(s[idx[1]])
        lst.append(s[idx[2]])
        lst.append(t[idx[0]])
        lst.append(t[idx[1]])
        lst.append(t[idx[2]])
 
        if (len(char_set) == 4) or (len(char_set) == 2):
            return "YES"
        elif len(char_set) == 3:
            for i in char_set:
                if lst.count(i) == 3:
                    return "YES"
            return "NO"
        else:
            return "NO"
 
T = int(input())
for _ in range(T):
    N = int(input())
    s = input()
    t = input()
    print(check_s_t(s, t))
