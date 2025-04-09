'''
4 de Abril de 2025
Solution D-Problem D (Krochanska) [Árboles y Grafos 2025-1]
Daniel Alejandro Posada Noguera (8980619)
'''

''' COMPLEJIDAD COMPUTACIONAL:
El algoritmo tiene una complejidad de O(k * (n + m)), donde n es el número total de estaciones del tren, m es el número de 
líneas y k es el número de estaciones importantes (a lo sumo 100). Esto se debe a que se ejecuta k veces el algoritmo que 
usa bfs para caminos más cortos, que tiene una complejidad de O(n + m).
'''

from sys import stdin, stdout
from collections import deque

MAX = 10000
INF = float('inf')
G = [[] for _ in range(MAX)]
importants = set()
n_stations = 0

def bfs_average(station):
    global n_stations, G, importants
    dist = [INF for _ in range(n_stations)]
    q = deque()
    dist[station], cnt = 0, 0 
    q.append(station)
    while len(q) > 0 and cnt < len(importants):
        u = q.popleft()
        if u in importants: cnt += 1
        for v in G[u]:
            if dist[v] == INF:
                dist[v] = dist[u] + 1
                q.append(v)
    total = 0
    for station in importants:
        total += dist[station]
    return total / len(importants)

def solve():
    global importants, G
    optimal_st = (-1, INF)
    for st in importants:
        d = bfs_average(st)
        if d < optimal_st[1]:
            optimal_st = (st, d)
        elif d == optimal_st[1]:
            optimal_st = (min(optimal_st[0], st), d)

    return optimal_st[0] + 1

def main():
    global n_stations, importants, G
    cases = int(stdin.readline())
    for _ in range(cases):
        n_stations, n_lines = list(map(int, stdin.readline().split()))
        for i in range(n_stations):
            G[i] = []
        has_line, importants = [False] * n_stations, set()
        for _ in range(n_lines):
            line_stations = list(map(int, stdin.readline().split()))
            for i in range(len(line_stations) - 1):
                station = line_stations[i] - 1
                if has_line[station]:
                    importants.add(station)
                else:
                    has_line[station] = True
                if i != len(line_stations) - 2:
                    G[station].append(line_stations[i + 1] - 1)
                    G[line_stations[i + 1] - 1].append(station)

        krochanska_st = solve()
        stdout.write(f"Krochanska is in: {krochanska_st}\n")

main()