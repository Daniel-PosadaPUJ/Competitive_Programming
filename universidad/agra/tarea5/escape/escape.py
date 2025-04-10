'''
4 de Abril de 2025
Solution A-Problem A (Escape) [Árboles y Grafos 2025-1]
Daniel Alejandro Posada Noguera (8980619)
'''

''' COMPLEJIDAD COMPUTACIONAL
El algoritmo tiene una complejidad de O((n + m) * log n) = O((n + m) * log n), donde n es el número de estados (1 por cada celda y 4 por puerta) 
y m es el número de conexiones entre habitaciones válidas (a lo sumo 4). Esto se debe a que se ejecuta el algoritmo de Dijkstra para hallar el camino
más corto en un grafo implícito de estados.
Se usa un grafo implícito, puesto que no es posible modelar adecuadamente la situación del problema usando unicamente la información que se da, principalmente
no es posible representar los cambios en las puertas y el tiempo que se tarda en moverlas.
'''

from sys import stdin, stdout
from collections import deque
from heapq import heappush, heappop

INF = float('inf')
doors, M = [], []
# Que forma existe que sea un poco más inteligente para ahorrarse las dos listas, tal vez con el módulo
out_doors = {'S' : 0, 'E': 1, 'N': 2, 'W': 3}
in_doors = {'N' : 0, 'W': 1, 'S': 2, 'E': 3}
change_doors = {'S' : ['E', 'W'], 'E': ['N', 'S'], 'N': ['W', 'E'], 'W': ['S', 'N']}
directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]

def create_dict_doors():
    global doors, M
    cost_doors, cnt = {}, 0
    for i in range(len(M)):
        for j in range(len(M[i])):
            if M[i][j] != '#' and M[i][j] != '.':
                cost_doors[(i, j)] = doors[cnt]
                cnt += 1
    return cost_doors

def escape(cost_doors):
    global M, directions
    n, m = len(M), len(M[0])
    min_time, found, pqueue = INF, False, []
    dist = {(n - 1, 0, '.') : 0}
    heappush(pqueue, (0, n - 1, 0, '.')) # (time, i, j, type)
    while len(pqueue) > 0 and not found:
        time, i, j, tipo = heappop(pqueue)
        if i == 0 and j == m - 1:
            found = True
            min_time = time
        elif dist[(i, j, tipo)] == time:
            if tipo == '.':
                # Se exploran los caminos libres
                for k in range(len(directions)):
                    di, dj = i + directions[k][0], j + directions[k][1]
                    is_pos_valid = (0 <= di and di < n) and (0 <= dj and dj < m) 
                    is_room_valid = is_pos_valid and (M[di][dj] != '#') and (M[di][dj] == '.' or in_doors[M[di][dj]] == k)
                    is_valid = is_room_valid and (di, dj, M[di][dj]) not in dist # or dist[(di, dj, M[di][dj])] > time + 1
                    if is_valid:
                        heappush(pqueue, (time + 1, di, dj, M[di][dj]))
                        dist[(di, dj, M[di][dj])] = time + 1
            else:
                # Se explora la celda de salida
                di, dj = i + directions[out_doors[tipo]][0], j + directions[out_doors[tipo]][1]
                is_pos_valid = (0 <= di and di < n) and (0 <= dj and dj < m)
                is_room_valid = is_pos_valid and (M[di][dj] != '#') and (M[di][dj] == '.' or in_doors[M[di][dj]] == k)
                is_valid = is_room_valid and (di, dj, M[di][dj]) not in dist # or dist[(di, dj, M[di][dj])] > time + 1
                if is_valid:
                    heappush(pqueue, (time + 1, di, dj, M[di][dj]))
                    dist[(di, dj, M[di][dj])] = time + 1
                # Se exploran los giros de las puertas
                for door in change_doors[tipo]:
                    if (i, j, door) not in dist:
                        heappush(pqueue, (time + cost_doors[(i, j)], i, j, door))
                        dist[(i, j, door)] = time + cost_doors[(i, j)]
            
    return min_time

def solve():
    cost_doors = create_dict_doors()
    min_time = escape(cost_doors)
    return min_time

def main():
    global M, doors
    cases = int(stdin.readline())
    for _ in range(cases):
        n, _ = list(map(int, stdin.readline().split()))
        M = []
        for _ in range(n):
            M.append(str(stdin.readline().strip()))
        doors = list(map(int, stdin.readline().split()))

        min_time = solve()
        if min_time == INF:
            stdout.write("Poor Kianoosh\n")
        else:
            stdout.write(f"{min_time}\n")

main()