'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

from sys import stdin,stdout
import array as arr
    
length = int(stdin.readline())
for _ in range(length):
    players, updates = stdin.readline().split()
    scores = stdin.readline().split()
    sc_set = set()
    sc_dict = {}
    for i in scores:
        sc_set.add(i)
        sc_dict[i]=sc_dict.get(i,0)+1
    for _ in range(int(updates)):
        player, new_score = stdin.readline().split()
        current_element = scores[int(player)-1]
        sc_dict[current_element]-=1
        if sc_dict[current_element] == 0:
            sc_set.remove(current_element)
        scores[int(player)-1]=new_score
        sc_dict[new_score]=sc_dict.get(new_score, 0)+1
        sc_set.add(new_score)
        stdout.write(f"{len(sc_set)+1}\n")
