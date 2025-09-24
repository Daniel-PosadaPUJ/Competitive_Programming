'''
Solution Problem 10610 Gopher and Hawks
Daniel Alejandro Posada Noguera
14 de Julio de 2025
'''

from sys import stdin, stdout
from collections import deque
from math import sqrt

v, m = int(), int()

class Hole:
    def __init__(self, pos=(0, 0)):
        self.x, self.y = pos
    
    def _distance_to(self, other):
        dist_x = (self.x - other.x) ** 2
        dist_y = (self.y - other.y) ** 2
        return sqrt(dist_x + dist_y)
    
    def _time_to(self, other):
        return self._distance_to(other) / v
    
    def go_is_secure(self, other):
        return self._time_to(other) <= m * 60
    
    def __eq__(self, other):
        return isinstance(other, Hole) and self.x == other.x and self.y == other.y
    
    def __hash__(self): 
        '''
        Busca alguna forma de representar numericamente el objeto, para poder usar sets o diccionarios, 
        y como python ya tiene implementada una función que lo hace para parejas de floats, se usa dicha función.
        '''
        return hash((self.x, self.y))

start, target, gopher_h = Hole(), Hole(), Hole()
ntvis_holes = set()

def bfs_gopher():
    global ntvis_holes, start, target
    found, cnt = False, -1
    q = deque([(start, 0)])

    while len(q) > 0 and not found:
        u, du = q.popleft()
        aux = ntvis_holes.copy()
        if u.go_is_secure(target):
            found = True
            cnt = du
        else:
            for v in aux:
                if u.go_is_secure(v):
                    q.append((v, du + 1))
                    ntvis_holes.remove(v)
    return cnt

def solve():
    sol = bfs_gopher()
    if sol != -1:
        stdout.write(f"Yes, visiting {sol} other holes.\n")
    else:
        stdout.write("No.\n")

cases = 1
def main():
    global v, m, start, target, gopher_h, ntvis_holes, cases
    v, m = list(map(float, stdin.readline().split()))
    while(v != 0 and m != 0):
        start = Hole(tuple(map(float, stdin.readline().split())))
        target = Hole(tuple(map(float, stdin.readline().split())))
        ntvis_holes.clear()
        gopher_h = stdin.readline().strip()
        while(gopher_h != ""):
            gopher_h = tuple(map(float, gopher_h.split()))
            ntvis_holes.add(Hole(gopher_h))
            gopher_h = stdin.readline().strip()
        solve()
        v, m = list(map(float, stdin.readline().split()))

main()