'''
26 de Enero de 2025
Solution B-Problem B (Drutojan) [Árboles y Grafos 2025-1]
Daniel Alejandro Posada Noguera (8980619)
'''

### Complejidad
# Véase que T(n) E O(n/m), puesto que cada una de las operaciones con los diccionarios es O(1) y el ciclo 
# while se ejecuta n/m veces en el peor de los casos.

from collections import deque

def drutojan(times_passengers, lists_passengers, n, m, single_person):
    trip_minutes = 0
    while trip_minutes + m <= n:
        times_passengers[single_person] += m
        trip_minutes += m
        next_person = lists_passengers[single_person].popleft()
        lists_passengers[single_person].append(next_person)
        trip_minutes += 2
        single_person = next_person
        
    if n - trip_minutes > 0:
        times_passengers[single_person] += n - trip_minutes
    
def main():
    cases = int(input())
    for i in range(1, cases + 1):
        times_passengers = {"Ja": 0, "Sam": 0, "Sha": 0, "Sid": 0, "Tan": 0}
        m, n, single_person = input().split()
        m = int(m)
        n = int(n)
        lists_passengers = {}
        for person in times_passengers.keys():
            lists_passengers[person] = deque(input().split()[1:])
        drutojan(times_passengers, lists_passengers, n, m, single_person)
        print(f"Case {i}:")
        for person, time in times_passengers.items():
            print(f"{person} {time}")
            

if __name__ == "__main__":
    main()