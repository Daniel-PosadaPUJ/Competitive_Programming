''' Solution Problem 776 Monkeys in a Regular Forest
2 de Julio de 2025
Daniel Alejandro Posada Noguera
'''

from sys import stdin, stdout
from collections import deque

forest = []
vis, n, m = [], 0, 0
dir = [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (-1, -1), (1, -1), (-1, 1)]

def bfs_monkeys(x, y, num):
    global forest, n, m, vis
    tree = forest[x][y]
    q = deque()
    forest[x][y] = num
    vis[x][y] = True
    q.append((x, y))

    while(len(q) > 0):
        i, j = q.popleft()
        for (di, dj) in dir:
            ni = i + di
            nj = j + dj
            if ni > -1 and nj > -1 and ni < n and nj < m and forest[ni][nj] == tree:
                q.append((ni, nj))
                vis[ni][nj] = True
                forest[ni][nj] = num

def print_matrix():
    global n, m, forest
    column_widths = [0] * m

    for i in range(n):
        for j in range(m):
            val = forest[i][j]
            column_widths[j] = max(column_widths[j], len(str(val)))

    for i in range(n):
        formatted_row = []
        for j in range(m):
            val = forest[i][j]
            formatted_row.append(f"{val:>{column_widths[j]}}")
        line = ' '.join(formatted_row)
        stdout.write(f"{line}\n")
    stdout.write("%\n")

def solve():
    global vis, n, m, forest
    num = 1
    vis = [[False for _ in range(m)] for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if not vis[i][j]:
                bfs_monkeys(i, j, num)
                num += 1

    print_matrix()

def main():
    global forest, n, m
    program_stop = False
    while(not program_stop):
        case_stop = False
        forest.clear()
        while(not case_stop):
            line = stdin.readline().strip()
            if len(line) > 0:
                if line != '%':
                    forest.append(line.split())
                else:
                    case_stop = True
            else:
                case_stop = True
                program_stop = True
        n = len(forest)
        m = len(forest[0])
        solve()

main()