'''
Solution Problem [A. Add or XOR] (Codeforces)
Daniel Alejandro Posada Noguera
Septiembre 1 de 2025
- Primer problema Codeforces
'''

from sys import stdin, stdout

def solve(a, b, x, y):
    ans = 0
    if b < a:
        if b == a - 1 and not a % 2 == 0:
            ans = y
        else:
            ans = -1
    else:
        d = b - a
        if d % 2 == 0:
            ans = (d / 2) * (x + min(x, y))
        else:
            if a % 2 == 0:
                ans = (d // 2) * x + (d - d // 2) * min(x, y)
            else:
                ans = (d - d // 2) * x + (d // 2) * min(x, y)
        
    return int(ans)

def main():
    t = int(stdin.readline())
    for _ in range(t):
        a, b, x, y = map(int, stdin.readline().split())
        sol = solve(a, b, x, y)
        stdout.write(f"{sol}\n")
main()