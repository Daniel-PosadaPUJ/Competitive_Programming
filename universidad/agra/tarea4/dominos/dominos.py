'''
23 de Marzo de 2025
Solution B-Problem B (Dominos) [Árboles y Grafos 2025-1]
Daniel Alejandro Posada Noguera (8980619)
'''

''' Complejidad Computacional: O(2(n + m) + n) = O(n + m)
Donde n es el número de dominos (nodos) y m el número de empujones en el grafo entre dominos (aristas), ya que se recorren 
todos los nodos y aristas del grafo dos veces. Una en el algoritmo de Gabow para encontrar los componentes fuertemente conexos 
y otra en la construcción del grafo de componentes. Por último, se recorre cada componente para determinar cuántos de ellos
no tienen aristas entrantes y así determinar cuántos dominos se deben tirar para que todos caigan, esto es O(n) en el peor de los casos.
'''

from sys import stdin, stdout, setrecursionlimit

setrecursionlimit(10**6)

MAX = 100000
graph = [[] for _ in range(MAX)]
visited = [0]*MAX
scc_ind = [-1]*MAX
n, numSCC, t = 0, 0, 0
pila_raiz, pila_vis, scc_nodos  = [], [], []
component_graph = []

def gabowAux(u):
    global n, numSCC, t, pila_raiz, pila_vis, scc_nodos
    t += 1
    visited[u] = t
    pila_raiz.append(u)
    pila_vis.append(u)

    for i in range(len(graph[u])):
        w = graph[u][i]
        if visited[w] == -1:
            gabowAux(w)
        elif scc_ind[w] == -1:
            while visited[pila_raiz[-1]] > visited[w]:
                pila_raiz.pop()

    if u == pila_raiz[-1]:
        numSCC += 1
        scc_nodos.append([])
        while pila_vis[-1] != u:
            v = pila_vis.pop()
            scc_ind[v] = numSCC - 1
            scc_nodos[numSCC - 1].append(v)

        v = pila_vis.pop()
        scc_ind[v] = numSCC - 1
        scc_nodos[numSCC - 1].append(v)
        pila_raiz.pop()

def gabow():
    global n, t, graph, numSCC, scc_nodos
    numSCC, t = 0, 0
    scc_nodos = []

    for i in range(n):
        visited[i], scc_ind[i] = -1, -1
    
    for i in range(n):
        if visited[i] == -1:
            gabowAux(i)

def build_components_graph():
    global n, component_graph
    component_graph = [set() for _ in range(numSCC)]
    for i in range(n):
        for j in range(len(graph[i])):
            if scc_ind[i] != scc_ind[graph[i][j]]:
                component_graph[scc_ind[graph[i][j]]].add(scc_ind[i])

def solve():
    min_dominos = 0
    gabow()
    build_components_graph()
    for i in range(numSCC):
        if len(component_graph[i]) == 0:
            min_dominos += 1

    return min_dominos

def main():
    cases = int(stdin.readline())
    global n, graph
    for _ in range(cases):
        n, m = list(map(int, stdin.readline().split()))
        for i in range(n):
            graph[i] = []
        for _ in range(m):
            u, v = list(map(int, stdin.readline().split()))
            graph[u-1].append(v-1)

        sol = solve()
        stdout.write(f"{sol}\n")

main()