'''
24 de Marzo de 2025
Solution A-Problem A (Critical) [Árboles y Grafos 2025-1]
Daniel Alejandro Posada Noguera (8980619)
'''

''' Complejidad Computacional: O(n + m) 

'''

from sys import stdin,  stdout, setrecursionlimit

setrecursionlimit(10**6)

MAX = 100000
capacities = []
graph = [[] for _ in range(MAX)]
visited = [-1 for _ in range(MAX)]
low = [-1 for _ in range(MAX)]
father = [-1 for _ in range(MAX)]
articulation_points = []
t, n, numSCC = 0, 0, 0

def select_critical_station():
    global capacities, articulation_points, numSCC
    identifier, affected = 0, 0
    max_len, max_cap, min_id = -1, -1, MAX

    for i in range(numSCC):
        if articulation_points[i][1] > max_len:
            max_len = articulation_points[i][1]
    
    for i in range(numSCC):
        if articulation_points[i][1] == max_len:
            for j in articulation_points[i][0]:
                max_cap = max(max_cap, capacities[j])

    for i in range(numSCC):
        if articulation_points[i][1] == max_len:
            for j in articulation_points[i][0]:
                if capacities[j] == max_cap:
                    min_id = min(min_id, j)

    affected, identifier = max_len, min_id
    
    return identifier, affected

def articulation_points_scc(v):
    global low, visited, father, articulation_points, t, numSCC, n, visited
    num_childrens = 0
    t += 1
    visited[v] = low[v] = t

    for w in graph[v]:
        if visited[w] == -1:
            num_childrens += 1
            father[w] = v
            articulation_points[numSCC][1] += 1
            articulation_points_scc(w)
            low[v] = min(low[v], low[w])

            if father[v] != -1 and low[w] >= visited[v]:
                articulation_points[numSCC][0].add(v)

        elif w != father[v]:
            low[v] = min(low[v], visited[w])

    if father[v] == -1 and num_childrens > 1:
        articulation_points[numSCC][0].add(v)

def critical():
    global low, visited, t, articulation_points, numSCC, n, father
    low = visited = father = [-1 for _ in range(n)]
    articulation_points = []
    numSCC, t = 0, 0

    for i in range(n):
        if visited[i] == -1:
            articulation_points.append([set(), 0])
            articulation_points_scc(i)
            numSCC += 1

    identifier, affected = select_critical_station()
    return identifier, affected

def main():
    global n, capacities
    line = stdin.readline()
    while line:
        n, m = list(map(int, line.split()))
        capacities = list(map(int, stdin.readline().split()))

        for i in range(n):
            graph[i].clear()

        for _ in range(m):
            u, v = list(map(int, stdin.readline().split()))
            graph[u].append(v)
            graph[v].append(u)

        identifier, affected = critical()
        stdout.write(f"{identifier} {affected}\n")
        line = stdin.readline()

main()