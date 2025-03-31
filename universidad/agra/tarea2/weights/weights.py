'''
16 de Febrero de 2025
Solution C-Problem C (Weights) [Árboles y Grafos 2025-1]
Daniel Alejandro Posada Noguera (8980619)
'''

''' Complejidad:
Tenemos para este caso que la complejidad de esta solución es O(n log k) en el peor de los casos,
donde n es la cantidad de pesas por cada fila, y k es el peso máximo.
Esto porque hacemos una búsqueda binaria sobre un arreglo implícito que tiene todos los valores 
entre 0 y el peso máximo (k), y para cada valor en la búsqueda (Log k), verificamos si es posible ordenar
todo el gimnasio con pesas de menor o igual tamaño. Recorriendo a lo sumo todo el ginmasio (2n) por cada
valor en la búsqueda (Log k). 
'''

from sys import stdin 

def es_posible_ordenar_con_menores(n, gym):
    i, answer, prev = 0, True, None
    while i < len(gym) and answer:
        j = 0
        while j < len(gym[i]) and answer:
            v = gym[i][j]
            if(v > n):
                if prev == None: 
                    prev = v
                else:
                    answer = v == prev
                    if answer: prev = None
            j += 1
        if prev != None:
            answer = False
        i += 1   
    return answer

# corregir
def peso_maximo(gym):
    max_weight = None
    for row in gym:
        m = max(row)
        if max_weight == None or max_weight < m:
            max_weight = m
    return max_weight

def solve(gym):
    max_weight = peso_maximo(gym)
    left, right = 0, max_weight 
    while left < right:
        mid = (left + right) // 2
        if es_posible_ordenar_con_menores(mid, gym):
            right = mid 
        else:
            left = mid + 1 
    return left    

def main():
    n = stdin.readline()
    result, upp, bott, gym = None, None, None, None
    while n != "":
        n = int(n)
        upp = list(map(int, stdin.readline().split()))
        bott = list(map(int, stdin.readline().split()))
        gym = [upp, bott]
        
        result = solve(gym)
        print(result)
        n = stdin.readline()
   
main()