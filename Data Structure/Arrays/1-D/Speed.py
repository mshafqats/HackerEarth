'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def solve(cars: list):
    previous = float('inf')
    fullspeed = 0
    for car in cars:
        if car <= previous:
            fullspeed += 1
            previous = car
    return fullspeed
 
def main():
    T = int(input())
 
    for tc in range(T):
        n = int(input())
        cars = list(map(int, input().split()))
 
        ans = solve(cars)
        print(ans)

if __name__ == "__main__":
    main()
