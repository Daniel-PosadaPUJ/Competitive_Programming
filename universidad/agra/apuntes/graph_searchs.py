'''
Apuntes y Algoritmos. DFS y BFS
Daniel Alejandro Posada (28/02/2025)
'''

# Recorridos usuales sobre grafos

# DFS (Depht First Search) 

# [Listas de adyacencia]
def dfsAux_LA(u, G, vis):
    vis[u] = True
    for v in G[u]:
        if not vis[v]:
            dfsAux(v, G, vis)

def dfs_LA(G):
    vis = [False for _ in range(len(G))]
    for u in range(len(G)):
        if not vis[u]:
            dfsAux(u, G, vis)