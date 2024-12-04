'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

from sys import stdin, stdout
 
def main ():
    input()
    a = [int(x) for x in stdin.readline ().split()]
    b = [int(x) for x in stdin.readline ().split()]
    out = []
    for _ in range(int(stdin.readline ().strip())):
        u, v = map(int, stdin.readline ().split())
        x = a[u - 1] + b[v - 1]
        u, v = map(int, stdin.readline ().split())
        y = a[u - 1] + b[v - 1]
        out.append("YES" if x % 2 == y % 2 else "NO")
    stdout.write ("\n".join(out))
 
if __name__ == "__main__":
    main ()
