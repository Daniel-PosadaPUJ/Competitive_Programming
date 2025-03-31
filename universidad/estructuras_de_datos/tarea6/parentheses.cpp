/* 
Solution C - Problem C (Parentheses)
Daniel Alejandro Posada Noguera 
Mayo 23 de 2024

*/

/*Análisis de Complejidad: 
Cada caso tiene una complejidad de O(n) donde n es el tamaño de la cadena de símbolos, puesto que en el peor de los casos
recorre solo una vez la cadena completa para determinar si es correcta o no.
 ---> Se concluye que la complejidad de la solución es T(n) E O(n) donde n es el tamaño de la cadena <---
*/

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool check( string &s ){
   bool ans = true;
   int i = 0, n = s.size();
   string simbol;
   stack<string> p; 

   while( i < n && ans ){
      simbol = s[ i ];
      if( simbol == "(" || simbol == "[" )
         p.push( simbol );
      else
         if( p.empty()  )
         	ans = false;
			else if( simbol == ")" && p.top() == "(" )
				p.pop();
			else if( simbol == "]" && p.top() == "[" )
				p.pop();
			else
				ans = false;
		i++;      
   }
   return ans;
}

int main(){
   bool ans;
   int cases;
   string aux;

   cin >> cases;
   cin.ignore();
   while( cases ){
      getline( cin, aux );
      ans = check( aux );
      if( ans )
         cout << "Yes" << endl;
      else
         cout << "No" << endl; 
      cases--;
   }
   return 0;
}