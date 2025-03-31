"""
Nombre: Daniel Alejandro Posada Noguera
Codigo: 8980619
Fecha: 09/02/2024
"""

#Punto 1

def fibonacciRecursiva( n ):
    num = 0

    if n == 0:
        num = 0
    elif n == 1:
        num = 1
    else:
        num = fibonacciRecursiva( n - 1 ) + fibonacciRecursiva( n - 2 )

    return num


#Punto 2 (Explícito)
def fibonacciExplicita( n ):

    num = int( ( 1 / 5**(1/2) ) * ( ( 1 + 5**(1/2) ) / 2 ) ** n + 1 / 2 ) 

    return num


#Punto 2 (Con ciclos)
def fibonacciCiclos( n ):
    a = 0
    b = 1
    if n <= 1:
        num = n

    elif n > 1:
        for i in range( n - 1 ): 
            num = a + b
            a = b
            b = num
    
    return num 


for i in range( 20 ):
    print( "Recursive: ", fibonacciRecursiva( i ) )
    print( "Explicit : ", fibonacciExplicita( i ) )
    print( "Ciclos: ", fibonacciCiclos( i ) )

