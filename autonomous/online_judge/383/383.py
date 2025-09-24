'''
Solution Problem 383 Shipping Routes
Daniel Alejandro Posada Noguera
23 de Julio de 2025
'''

from sys import stdin, stdout
from collections import deque

c, m, n, p, ac = int(), int(), int(), int(), int()
vis, graph, codes = [False for _ in range(30)], [[] for _ in range(30)], dict()

def initialize_values():
    global ac, m, codes
    ac = 0
    codes.clear()
    for i in range(m):
        graph[i].clear()
        vis[i] = False

def bfs_shipping(s, e):
    q, ans = deque(), -1
    found = False
    vis[s] = True
    q.append((s, 0))
    while(len(q) > 0 and not found):
        u, du = q.popleft()
        if u == e:
            found = True
            ans = du
        else:
            for v in graph[u]:
                if not vis[v]:
                    q.append((v, du + 1))
                    vis[v] = True
    
    return ans


def shipping_request(size, s, e):
    for i in range(m): vis[i] = False
    price = size * bfs_shipping(s, e) * 100
    if price >= 0: stdout.write(f"${price}\n")
    else: stdout.write("NO SHIPMENT POSSIBLE\n")

def solve():
    global c, p
    stdout.write(f"DATA SET  {c}\n\n")
    for _ in range(p):
        size, begin, end = stdin.readline().split()
        size = int(size); begin = codes[begin]; end = codes[end]
        shipping_request(size, begin, end)
    stdout.write("\n")

def main():
    global ac, c, m, n, p, graph, codes
    c = 1
    stdout.write("SHIPPING ROUTES OUTPUT\n\n")
    num_cases = int(stdin.readline())
    while(c <= num_cases):
        initialize_values()
        m, n, p = map(int, stdin.readline().split())
        aux = stdin.readline().split()
        for name in aux:
            codes[name] = ac
            ac += 1
        for _ in range(n):
            s, e = stdin.readline().split()
            graph[codes[s]].append(codes[e])
            graph[codes[e]].append(codes[s])

        solve()
        c += 1
    stdout.write("END OF OUTPUT\n")

main()