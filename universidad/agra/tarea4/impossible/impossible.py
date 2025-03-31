'''
20 de Marzo de 2025
Solution C-Problem C (Impossible) [Árboles y Grafos 2025-1]
Daniel Alejandro Posada Noguera (8980619)
'''

''' Complejidad Computacional: O(n + m) 
Donde n es el número de grupos de investigación y m el número de operaciones en el grafo, ya que se recorren todos los nodos y aristas
del grafo una sola vez en el algoritmo de Gabow para encontrar los componentes fuertemente conexos y se detiene
el algoritmo si se encuentra más de una sola componente fuertemente conexa. 
'''

from sys import stdin,  stdout, setrecursionlimit


setrecursionlimit(10**6)

max = 50000
graph = [[] for _ in range(max)]
visitado = [0 for _ in range(max)]
pilaRaiz, pilaVis, = [], []
n, t, numSCC = 0, 0, 0

''' Esta fue mi primera implementación, pero pensé que era más complicada y costosa
de lo que pensaba (no funciona así como está) y decidí hacerlo de otra forma, aunque
según mi intuición, si uno sigue con esta idea de transformar cada operación en un nodo
del grafo, creo que es una forma elegante de resolver el problema sin gabow (puesto que dicho grafo sería conexo
si tiene solo un nodo).

def addProcedure(G, units, procedure):
    k, *groups = procedure
    if k == 1:
        u, v = groups
        u -= 1
        v -= 1
        G[units.get(u, u)].append(units.get(v, v))
    else:
        i, j, areSame = 0, 0, False
        keys, g = units.keys(), -1
        while i < len(keys) and not areSame:
            while j < len(groups) and not areSame:
                node = groups[j] - 1
                if node in units[keys[i]]:
                    areSame = True
                    g = keys[i]
                j += 1
            i += 1
        
        groups_set = set(group - 1 for group in groups)
        if not areSame:
            node = groups[0] - 1
            units[node] = groups_set
        else: 
            units[g].union(groups_set) '
'''

def addProcedure(G, procedure):
    k, *groups = procedure
    for i in range(len(groups) - 1):
        G[groups[i] - 1].append(groups[i + 1] - 1)
    
    if k != 1:
        G[groups[-1] - 1].append(groups[0] - 1)

def isPossible():
    global numSCC, pilaRaiz, pilaVis, t 
    numSCC, pilaRaiz, pilaVis, t = 0, [], [], 0

    for i in range(n):
        visitado[i] = -1

    i, flag = 0, True
    while i < n and flag:
        if visitado[i] == -1:
            flag = gabowAux(i)
        i += 1  
    sol = "YES" if flag else "NO"
    return sol

def gabowAux(v):
    global t, numSCC
    t += 1
    visitado[v] = t
    pilaRaiz.append(v)
    pilaVis.append(v)
    
    i, flag = 0, numSCC < 1
    while i < len(graph[v]) and flag:
        w = graph[v][i]
        if visitado[w] == -1:
            flag = gabowAux(w) and numSCC < 1
        elif visitado[w] < visitado[v] and flag:
            while visitado[pilaRaiz[-1]] > visitado[w]:
                pilaRaiz.pop()
        i += 1

    if v == pilaRaiz[-1] and flag:
        numSCC += 1
        while pilaVis[-1] != v:
            pilaVis.pop()

        pilaVis.pop()
        pilaRaiz.pop()
    
    return flag

def main():
    line = stdin.readline()
    global n, graph
    while line:
        n, m = list(map(int, line.split()))
        # units = {}
        for i in range(n):
            graph[i] = []

        for _ in range(m):
            procedure = list(map(int, stdin.readline().split()))
            addProcedure(graph, procedure)
        sol = isPossible()
        stdout.write(f'{sol}\n')	

        line = stdin.readline()

main()