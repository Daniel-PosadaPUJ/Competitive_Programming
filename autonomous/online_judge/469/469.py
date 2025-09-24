'''
Solution Problem 469 Wetlands of Florida
1 de Julio de 2025
Daniel Alejandro Posada Noguera
'''

from sys import stdin, stdout
from collections import deque

florida, querys = [], []
n, m, k = 0, 0, 0
d = [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1)]

def count_water(pos):
    global n, m, k, florida, querys
    cnt = 0
    vis = [[False for _ in range(m)] for _ in range(n)]
    q = deque()
    vis[pos[0]][pos[1]] = True
    q.append(pos)

    while len(q) > 0:
        u = q.popleft()
        if florida[u[0]][u[1]] == 'W':
            cnt += 1
        for i in range(8):
            ni = u[0] + d[i][0]
            nj = u[1] + d[i][1]
            if ni >= 0 and nj >= 0 and ni < n and nj < m and florida[ni][nj] != 'L' and not vis[ni][nj]:
                q.append((ni, nj))
                vis[ni][nj] = True
    return cnt

def solve():
    global querys
    sol = []
    for q in querys:
        sol.append(count_water(q))
    return sol

def main():
    global n, m, k, florida, querys
    cases = int(stdin.readline())
    _ = str(stdin.readline().strip())
    for c in range(cases):
        case_stop = False
        florida.clear()
        querys.clear()
        while(not case_stop):
            line = str(stdin.readline().strip())
            if len(line) > 0:
                if line[0] == 'W' or line[0] == 'L':
                    florida.append(line)
                else:
                    q = tuple(map(int, line.split()))
                    querys.append((q[0] - 1, q[1] - 1))
            else:
                case_stop = True
        n = len(florida)
        m = len(florida[0])
        k = len(querys)
        solutions = solve()
        for s in solutions:
            stdout.write(f"{s}\n")
        if c < cases - 1: stdout.write("\n")

main()