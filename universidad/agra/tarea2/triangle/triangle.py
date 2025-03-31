'''
16 de Febrero de 2025
Solution B-Problem B (Triangle) [Árboles y Grafos 2025-1]
Daniel Alejandro Posada Noguera (8980619)
'''

''' Complejidad
En este caso, dado que usamos bisección sobre una lista de n elementos, tenemos que la complejidad
del algoritmo es O(log n). Donde n corresponde con la cantidad de elementos, que está dada por el 
cociente entre el tamaño del rango seleccionado d = value_max - value_min, y la tolerancia tol de error
esperada.
Para este caso particular, se tiene que siempre value_max = AB y value_min = 0, por lo que n = AB / tol.
Luego, como tol es un valor constante 1e-6, tenemos que O(log n) = O(log AB).
Por lo que en este caso la complejidad es logaritmica y depende únicamente de AB.
'''

from sys import stdin
import math

def f(ad, ab, ratio):
    return math.sqrt(ratio / (ratio + 1)) * ab - ad

def find_ad(ab, ratio):
    value_min, value_max = 0, ab
    x = None
    while abs(value_max - value_min) > 1e-10:
        x = (value_min + value_max) / 2
        y = f(x, ab, ratio)
        if y > 0:
            value_min = x
        else:
            value_max = x                          
    return x

def main():
    cases = int(stdin.readline())
    for i in range(1, cases + 1):
        ab, ac, bc, ratio = stdin.readline().split()
        ab = float(ab)
        ratio = float(ratio)
        ad = find_ad(ab, ratio)
        print("Case %d: %.6f" % (i, ad))  
          
main()