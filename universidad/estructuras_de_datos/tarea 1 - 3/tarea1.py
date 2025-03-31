"""
Nombre: Daniel Alejandro Posada Noguera
Codigo: 8980619
Fecha: 28/01/2024
"""

#Punto 1

def join( l, sep ): 

    cadenaResultante = ""
    for i in range( len( l ) ):
        cadenaResultante = cadenaResultante + l[i]
        if i < len( l ) - 1:
          cadenaResultante = cadenaResultante + sep
    return cadenaResultante


#Punto 2

def obtenerSumaFilaColumna( mat ):
   numLista = []
   n = len( mat )
   i, j = 0, 0
   

   for j in range( n ) :
      sumTempColum, sumTempFila = 0, 0
      for i in range( n ):
        sumTempFila = sumTempFila + mat[j][i]
        sumTempColum = sumTempColum + mat[i][j]

      numLista.append( sumTempColum + sumTempFila - mat[j][j] )

   return numLista


#Punto 3

def obtenerPalabras( cad1, cad2 ):
   dic = {}
   palabra = ""
   listaPalabras = []

   for i in range( len( cad2 ) ):
         dic[ cad2[ j ] ] = []

   for i in range( len( cad1 ) ):
      if cad1[ i ] != " ":
         palabra = palabra + cad1[ i ]
      else:
         listaPalabras.append( palabra )
         palabra = ""
   listaPalabras.append( palabra )

   listaPalabras.sort()

   for i in range( len( listaPalabras ) ):
      for j in range( len( cad2 ) ):
         if cad2[ j ] in listaPalabras[ i ]:
            dic[ cad2[ j ] ].append( listaPalabras[ i ] )

   return dic 


#Punto 4

#(a)
def esAntiaritmetica( l ):
   ans = True 
   times = 0
   n = len( l )
   d = ( n - 1 )//2
   i, j, m = 1, 0, 0

   while ans and d > 0 and m < n - 2: 
      if times >= 2:
         ans = False

      if i == n:
         i %= n
         m += 1
         j = m
         d-= 1
         times = 0

      if abs( l[ j ] - l[ i ] ) == d:
         j = i
         times += 1

      i += 1

   return ans 


#(b)
def mainAntiaritmetica(): 
   x = int( input() )

   for i in range( x ):
      n = int( input() )
      numbers = input()
      l = [ int( i ) for i in numbers.split() ]
      if esAntiaritmetica( l ):
         print( f"---> La lista { tuple( l ) } es antiaritmética." )
      else:
         print( f"---> La lista { tuple( l ) } no es antiaritmética." )
   


mainAntiaritmetica()

#Punto 5
def mostrarCoprimos( N ):
   coprimos = [ 1 ]
   suma = 0
   q = 0
   m = 1
   if N % 2:
      q = 1
      m = 2

   for i in range( 2 + q, N, m ):
      a = N
      b = i
      while b > 0:
         r = a % b
         a = b
         b = r
      if a == 1: 
         coprimos.append( i )    
 
   print( f"Números coprimos de { N }:\n" )
   for i in range( len( coprimos ) ):
      suma += coprimos[ i ]
      if i < len( coprimos ) - 1:
         print( f"{ i + 1 }) { coprimos[ i ]}," )
      else: 
         print( f"{ i + 1 }) { coprimos[ i ]}" )
   print( f"\n Suma de los coprimos del número { N }:{ suma }" )
 
