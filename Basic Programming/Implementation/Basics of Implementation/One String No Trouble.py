'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def noTrouble(s):
    sum=1
    max=1
 
    for i in range(1,len(s)):
        if s[i]!=s[i-1]:
            sum+=1
        else:
            if sum>max:
                max=sum
            sum=1
 
    if sum>max:
        max=sum
    return max
 
if __name__=='__main__':
    s=input()
    print(noTrouble(s))