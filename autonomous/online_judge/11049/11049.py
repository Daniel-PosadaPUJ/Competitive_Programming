'''
Solution Problem 11049  Basic wall maze
Daniel Alejandro Posada Noguera
16 de Julio de 2025
'''

from sys import stdin, stdout
from collections import deque

start, end = int(), int()
d, m = [(-1, 0), (0, 1), (1, 0), (0, -1)], ['N', 'E', 'S', 'W']
maze = [[0 for _ in range(6)] for _ in range(6)]
vis = [[False for _ in range(6)] for _ in range(6)]
routes = [[[] for _ in range(6)] for _ in range(6)]

def addWalls(x1, y1, x2, y2):
    if x1 < x2:
        i = x1
        while(i < x2):
            maze[i][y2 - 1] += 2
            i += 1
    else:
        j = y1
        while(j < y2 and x2 < 6):
            maze[x2][j] += 1
            j += 1

def initializeValues():
    global start, end, maze, vis, routes
    end = (end[1] - 1, end[0] - 1)
    start = (start[1] - 1, start[0] - 1)
    for i in range(6):
        for j in range(6):
            maze[i][j] = 0
            vis[i][j] = False
            routes[i][j] = []

def isValid(posu, posv, k):
    global maze
    ans = (-1 < posv[0] and posv[0] < 6) and (-1 < posv[1] and posv[1] < 6)
    if ans:
        if k == 0:
            ans &= not (maze[posu[0]][posu[1]] == 1 or maze[posu[0]][posu[1]] == 3)
        elif k == 1:
            ans &= not (maze[posu[0]][posu[1]] == 2 or maze[posu[0]][posu[1]] == 3)
        elif k == 2:
            ans &= not (maze[posv[0]][posv[1]] == 1 or maze[posv[0]][posv[1]] == 3)
        else:
            ans &= not (maze[posv[0]][posv[1]] == 2 or maze[posv[0]][posv[1]] == 3)
    return ans

def bfs_simple():
    global start, end, vis, routes
    vis[start[0]][start[1]] = True
    q = deque([start])
    found = False
    while len(q) > 0 and not found:
        x, y = q.popleft()
        if (x, y) == end:
            found = True
        else:
            for k in range(4):
                nx, ny = x + d[k][0], y + d[k][1]
                if isValid((x, y), (nx, ny), k) and not vis[nx][ny]:
                    q.append((nx, ny))
                    vis[nx][ny] = True
                    routes[nx][ny] = list(routes[x][y])
                    routes[nx][ny].append(f"{m[k]}")

    return "".join(routes[end[0]][end[1]])

def solve():
    path = bfs_simple()
    stdout.write(f"{path}\n")

def main():
    global start, end, maze
    start = tuple(map(int, stdin.readline().split()))
    while(start != (0, 0)):
        end = tuple(map(int, stdin.readline().split()))
        initializeValues()
        for _ in range(3):
            y1, x1, y2, x2 = map(int, stdin.readline().split())
            addWalls(x1, y1, x2, y2)
        solve()
        start = tuple(map(int, stdin.readline().split()))

main()