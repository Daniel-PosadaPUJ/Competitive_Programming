'''
Solution Parcial Práctico Opcional (Zlatan)
Daniel Alejandro Posada Noguera
Árboles y Grafos (AGRA)
'''
from sys import stdin
from collections import deque

def number_from_digits(digits):
    number = 0
    for i in range(len(digits)):
        number += digits[i] * pow(10, len(digits) - 1 - i)
    return number

def bfs_aux(initial, target, vis):
    q = deque()
    changes = [-1, 1]
    flag, d_answer = False, -1
    q.append((initial, 0))
    vis[number_from_digits(initial)] = 1
    
    while len(q) > 0 and not flag:
        num, distance = q.popleft()
        if target == num: 
            flag, d_answer = True, distance
        else:
            for i in range(len(num)):
                for c in changes:
                    aux = num[:]
                    aux[i] = (aux[i] + c) % 10
                    val = number_from_digits(aux)
                    if not vis[val]:
                        q.append((aux, distance + 1))
                        vis[val] = 1          
    return d_answer

def solve(initial, target, forbidenns):
    # 0 : no visitado, 1 : visitado, 2 : prohibido
    vis = [0 for _ in range(10000)]
    for i in range(len(forbidenns)):
        vis[forbidenns[i]] = 2
        
    ans = bfs_aux(initial, target, vis)
    return ans
    

def main():
    cases = int(stdin.readline())
    for _ in range(cases):
        initial = list(map(int, stdin.readline().split()))
        target = list(map(int, stdin.readline().split()))
        forbiddens = []
        n = int(stdin.readline())
        for _ in range(n):
            aux = number_from_digits(list(map(int, stdin.readline().split())))
            forbiddens.append(aux)
            
        ans = solve(initial, target, forbiddens)
        print(ans)
        
        _ = stdin.readline()
    
    
main()