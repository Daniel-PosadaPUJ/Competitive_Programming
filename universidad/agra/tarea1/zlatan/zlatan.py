'''
30 de Enero de 2025
Solution E-Problem E (Zlatan) [Árboles y Grafos 2025-1]
Daniel Alejandro Posada Noguera (8980619)
'''

### Complejidad:
# En este algoritmo se hace uso de técnicas de ordenamiento (de complejidad O(nlogn)), un diccionario (con operaciones O(1)) 
# y una cola de prioridad (de complejidad O(logn)). En general, se hacen n operaciones con el diccionario, n inserciones (O(logn)) a la cola de prioridad, 
# n extracciones (O(logn)) a la cola de prioridad y un ordenamiento de un vector de tamaño k (O(klogk)). Esto nos deja entonces con una complejidad de O(nlogn)
# en el peor de los casos.

from heapq import heappush, heappop
from sys import stdin

def print_solution(k_dup_cards):
    for card in k_dup_cards:
        print(f"{card[0]} {-card[1]}")

def zlatan_business(cards_collection, k):
    heap = []
    k_dup_cards = []
    for (name, serial) in cards_collection:
        amount = cards_collection[(name, serial)]
        card = (-amount, -serial, name)
        heappush(heap, card)
    for _ in range(k):
        card = heappop(heap)
        k_dup_cards.append((card[2], card[0], card[1]))

    k_dup_cards.sort()
    print_solution(k_dup_cards)

def main():
    n, k = stdin.readline().split()
    n = int(n)
    k = int(k)
    while(n and k):
        cards_collection = {}
        for _ in range(n):
            name, serial = stdin.readline().split()
            serial = int(serial)
            info_card = (name, serial)
            if info_card not in cards_collection:
                cards_collection[info_card] = 1
            else:
                cards_collection[info_card] += 1
        zlatan_business(cards_collection, k)
        n, k = input().split()
        n = int(n)
        k = int(k)

if __name__ == "__main__":
    main()