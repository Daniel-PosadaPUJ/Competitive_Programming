'''
Solution D - Problem D (Shipping)
Daniel Alejandro Posada Noguera
Árboles y Grafos (AGRA)
'''

''' COMPLEJIDAD TEMPORAL
La complejidad temporal de este algoritmo es O(P*(N + m)) donde N es el número de almacenes, M es el número
de conexiones entre almacenes y P es el número de envíos a realizar.
Esto se debe a que para cada envío se realiza un BFS sobre grafo de almacenes, la cual tiene
una complejidad de O(N + M) donde N es el número de nodos y M el número de aristas. 
Luego, como se hacen P envíos, la complejidad total del algoritmo será O(P*(N + M)).
'''

from sys import stdin
from collections import deque
      
def create_graph(warehouses, conections):
    G = {warehouse: [] for warehouse in warehouses}
    for conection in conections:
        G[conection[0]].append((conection[1]))
        G[conection[1]].append((conection[0]))
        
    return G
    
def bfs(data_set, vis, init, target):
    answer, flag = -1, False
    q = deque()
    q.append((init, 0))
    vis[init] = True
    
    while len(q) > 0 and not flag:
        warehouse = q.popleft()
        code = warehouse[0]
        distance = warehouse[1]
        if code == target:
            answer = distance
            flag = True
        else:
            for other_ware in data_set[code]:
                if not vis[other_ware]:
                    q.append((other_ware, distance + 1))
                    vis[other_ware] = True
    
    return answer
    
def solve(data_set, warehouses, init, target, size):
    vis = {warehouse: False for warehouse in warehouses}
    leg_counts = bfs(data_set, vis, init, target)
    if leg_counts != -1:
        print(f"${size * leg_counts * 100}")
    else:
        print("NO SHIPMENT POSSIBLE")
    
def main():
    print("SHIPPING ROUTES OUTPUT")
    cases = int(stdin.readline())
    for case in range(cases):
        print(f"\nDATA SET {case + 1}\n")
        _, N, P = map(int, stdin.readline().split())
        warehouses = stdin.readline().split()
        conections = [stdin.readline().split() for _ in range(N)]
        data_set = create_graph(warehouses, conections)
        for _ in range(P):
            size, init, target = stdin.readline().split()
            size = int(size)
            solve(data_set, warehouses, init, target, size)
    
    print("\nEND OF OUTPUT")
    
       
main()