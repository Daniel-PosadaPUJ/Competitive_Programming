'''
4 de Abril de 2025
Solution A-Problem A (Cards) [Árboles y Grafos 2025-1]
Daniel Alejandro Posada Noguera (8980619)
'''

''' COMPLEJIDAD COMPUTACIONAL
El algoritmo tiene una complejidad de O(2 * (n + m) * log n) = O((n + m) * log n), donde n es el número de paradas 
y m es el número de líneas de bus. Esto se debe a que se ejecuta el algoritmo de Dijkstra dos veces,
una para el grafo original (hallando los precios de la CCS a todos los nodos) y otra para el grafo transpuesto (hallando 
los precios de todos los nodos a la CCS).
'''

from sys import stdin, stdout
from collections import deque
from heapq import heappush, heappop

MAX = 1000000
INF = float('inf')
G = [[] for _ in range(MAX)]
GT = [[] for _ in range(MAX)]
n_stops = 0

def dijkstra_distance_all(G, s):
    global n_stops
    dist = [INF] * n_stops
    dist[s], pqueue = 0, []
    heappush(pqueue, (dist[s], s))
    while len(pqueue) > 0:
        du, u = heappop(pqueue)
        if du == dist[u]:
            for v, duv in G[u]:
                if du + duv < dist[v]:
                    dist[v] = du + duv
                    heappush(pqueue, (dist[v], v))

    return sum(dist)

def solve():
    global G, GT
    min_cost = dijkstra_distance_all(G, 0) + dijkstra_distance_all(GT, 0)

    return min_cost

def main():
    global n_stops, G, GT
    cases = int(stdin.readline())
    for _ in range(cases):
        n_stops, n_lines = list(map(int, stdin.readline().split()))
        for i in range(n_stops):
            G[i] = []
            GT[i] = []
        for i in range(n_lines):
            orig, dest, price = list(map(int, stdin.readline().split()))
            G[orig - 1].append((dest - 1, price))
            GT[dest - 1].append((orig - 1, price))
        
        min_cost = solve()
        stdout.write(f"{min_cost}\n")

main()