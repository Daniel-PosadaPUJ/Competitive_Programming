'''
Apuntes y Algoritmos. Búsqueda binaria
Daniel Alejandro Posada (28/02/2025)
'''

# Busqueda Binaria Usual

# Variación 1 (Intervalo [r, l])
def binary_search_1(A, v):
    ans = False
    l, r = 0, len(A) - 1
    while l <= r and not ans:
        mid = (l + r) // 2
        if A[mid] == v:
            ans = True
        elif A[mid] > v:
            r = mid - 1
        else:
            l = mid + 1
    if not ans:
        mid = -1
        
    return mid

#Variación 2 (Intervalo [r, l))
def binary_search_2(A, v):
    ans = False
    l, r = 0, len(A)
    while l < r and not ans:
        mid = (l + r) // 2
        if A[mid] == v:
            ans = True
        elif A[mid] > v:
            r = mid
        else:
            l = mid + 1
            
    if not ans:
        mid = -1
        
    return mid
    
    
#    0, 1, 2, 3, 4, 5, 6, 7, 8
A = [1, 1, 2, 2, 2, 3, 3, 4, 4]

print(binary_search_1(A, 0))
print(binary_search_2(A, 4))


# Modificaciones Usuales del algoritmo

# Encontrar el primer elemento de A que es igual a v
def find_lower_bound(A, v):
    l, r = 0, len(A) - 1
    while l < r:
        mid = (l + r) // 2
        if A[mid] >= v:
            r = mid
        else:
            l = mid + 1
            
    if l > len(A) or A[l] != v:
        l = -1

    return l

# Encontrar el último elemento de A que es igual a v:
def find_upper_bound(A, v):
    l, r = 0, len(A) - 1
    while l < r:
        mid = (l + r + 1) // 2
        if A[mid] <= v:
            l = mid
        else:
            r = mid - 1

    if l > len(A) or A[l] != v:
        l = -1

    return l

#    0, 1, 2, 3, 4, 5, 6, 7, 8
A = [1, 1, 2, 2, 2, 3, 3, 4, 4]

# Encontrar la cantidad de veces que aparece un elemento v en el arreglo
def amount_of_1(A, v):
    low = find_lower_bound(A, v)
    up = find_upper_bound(A, v)

    return up - low + 1

def amount_of_2(A, v):
    l1, r1 = 0, len(A) - 1
    l2, r2 = 0, len(A) - 1
    while l1 < r1 or l2 < r2:
        mid1 = (l1 + r1) // 2
        mid2 = (l2 + r2 + 1) // 2
        if A[mid1] >= v:
            r1 = mid1
        else:
            l1 = mid1 + 1
            
        if A[mid2] <= v:
            l2 = mid2
        else:
            r2 = mid2 - 1

    amount = l2 - l1 + 1

    if l1 > len(A) or l2 > len(A) or A[l1] != v or A[l2] != v:
        amount = 0

    return amount


print(amount_of_2(A, 0))