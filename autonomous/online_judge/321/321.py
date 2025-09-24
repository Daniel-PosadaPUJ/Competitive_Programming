'''
Solution Problem 321 The New Villa
Daniel Alejandro Posada Noguera
15 de Julio de 2025
'''

from sys import stdin, stdout
from collections import deque

r, d, s = int(), int(), int()
g_rooms, g_lights = [[] for _ in range(12)], [[] for _ in range(12)]
routes, found = dict(), False
num_villa, options = 1, ["Switch off light in room", "Switch on light in room", "Move to room"]

def bfs_villa():
    global r, d, s, routes, g_rooms, g_lights, found
    found, ans = False, deque()
    routes = {(0, 1) : deque()} #state: (room, lights_on)
    q = deque([(0, 1)]) 
    while len(q) > 0 and not found:
        room_u, lights = q.popleft()
        if room_u == r - 1 and lights == (1 << (r - 1)):
            found = True
            ans = routes[(room_u, lights)]
        else: 
            for room_v in g_rooms[room_u]:
                if lights & (1 << room_v) and (room_v, lights) not in routes:
                    q.append((room_v, lights))
                    routes[(room_v, lights)] = deque(routes[(room_u, lights)]) 
                    routes[(room_v, lights)].append((2, room_v))
            for lroom_v in g_lights[room_u]:
                new_lights = lights ^ (1 << lroom_v)
                if new_lights & (1 << room_u) and (room_u, new_lights) not in routes:
                    q.append((room_u, new_lights))
                    step = 0 if lights & (1 << lroom_v) else 1
                    routes[(room_u, new_lights)] = deque(routes[(room_u, lights)]) 
                    routes[(room_u, new_lights)].append((step, lroom_v))
    return ans

def solve():
    global num_villa, options, found
    stdout.write(f"Villa #{num_villa}\n")
    steps = bfs_villa()
    if found:
        stdout.write(f"The problem can be solved in {len(steps)} steps:\n")
        while len(steps) > 0:
            rule, room = steps.popleft()
            stdout.write(f"- {options[rule]} {room + 1}.\n")
    else:
        stdout.write("The problem cannot be solved.\n")
    stdout.write("\n")
    num_villa += 1

def main():
    global g_rooms, g_lights, r, d, s
    r, d, s = list(map(int, stdin.readline().split()))
    while(r != 0 or d != 0 or s != 0):
        for i in range(r):
            g_rooms[i].clear()
            g_lights[i].clear()
        for _ in range(d):
            u, v = list(map(int, stdin.readline().split()))
            g_rooms[u - 1].append(v - 1)
            g_rooms[v - 1].append(u - 1)
        for _ in range(s):
            k, l = list(map(int, stdin.readline().split()))
            g_lights[k - 1].append(l - 1)
        solve()
        _ = stdin.readline()
        r, d, s = list(map(int, stdin.readline().split()))
main()