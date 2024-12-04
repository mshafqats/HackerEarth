'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

from sys import stdin
 
def perpendicular_lines():
    for _ in range(int(stdin.readline())):
        res = ""
        x1,y1,x2,y2 = map(int,stdin.readline().split())
        x3,y3,x4,y4 = map(int,stdin.readline().split())
        if (x1==x2 and y1==y2) or (x3==x4 and y3==y4):
            res = "INVALID"
        elif (x2==x1 and y3==y4) or (x3==x4 and y1==y2):
            res = "YES"
        elif (x2==x1 and y3!=y4) or (x3==x4 and y1!=y2):
            res = "NO"
        else:
            m = ((y2-y1)*(y4-y3))/((x4-x3)*(x2-x1))
            if m == -1:
                res = "YES"
            elif (y4-y3)/(x4-x3) == (y4-y2)/(x4-x2) and (y4-y3)/(x4-x3) == (y2-y1)/(x2-x1):
                res = "INVALID"
            else:
                res = "NO"
        yield res
 
def main():
    print(*perpendicular_lines(),sep="\n")
    
if __name__ == "__main__":
    main()
