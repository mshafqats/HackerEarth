'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

def solve (N, start, finish, Ticket_cost):
    station_one, station_two = sorted((start, finish))
    route_one_cost = sum(Ticket_cost[(station_one - 1) : (station_two - 1)])
    another_route_cost = sum(Ticket_cost) - route_one_cost
    return sorted((route_one_cost, another_route_cost))[0]
 
N = int(input())
start = int(input())
finish = int(input())
Ticket_cost = list(map(int, input().split()))
out_ = solve(N, start, finish, Ticket_cost)
print (out_)
