/* 
Solution A - Problem A (Boxes)
Daniel Alejandro Posada Noguera 
Mayo 23 de 2024

*/

/*Análisis de Complejidad: 
Cada comando tiene una complejidad de O(1) contando con la lista de elementos y el vector de iteradores.
Garantizar la lista y el vector tiene una complejidad de O(n), y dada una cantidad m de comandos tenemos que:
 ---> Se concluye que la complejidad de la solución es T(n) E O(m) donde n es el tamaño de la lista 
 y m la cantidad de comandos ingresados <---
*/

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<list>

using namespace std;

void sortBoxes( int x, int y, int command, vector<list<int>::iterator> &iterators, list<int> &l, bool reversed ){
   list<int>::iterator it, it2;

   if( reversed && command != 3 ){
      if( command == 2 )
         command = 1;
      else  
         command = 2;
   }
	if( command == 3 ){
      *iterators[ x - 1 ] = y;
      *iterators[ y - 1 ] = x;
      it = iterators[ x - 1 ];
      iterators[ x - 1 ] = iterators[ y - 1 ];
      iterators[ y - 1 ] = it; 
   }
   else if( command == 2 ){
      it = iterators[ y - 1 ];
      it2 = l.insert( ++it, x );
      l.erase( iterators[ x - 1 ] );
      iterators[ x - 1 ] = it2; 
   }
   else{
      it = l.insert( iterators[ y - 1 ], x );
      l.erase( iterators[ x - 1 ] );
      iterators[ x - 1 ] = it; 
   }
}

long long int result( list<int> &l, bool f ){
	int cnt = 1;
	long long int sum = 0;
	list<int>::iterator it;
	if( f ){
		it = --l.end();
		while( it != l.begin() ){
			if( cnt % 2 != 0 )
				sum += *it;
			it--;
			cnt++;
      }
		if( cnt % 2 != 0 )
			sum += *it;
	}
	else{
		it = l.begin();
		while( it != l.end() ){
			if( cnt % 2 != 0 )
				sum += *it;
			it++;
			cnt++;
		}
	}
	return sum;
}

int main(){
	bool reversed;
   int boxes, instructions, value, command, x, y, cont = 0;
   long long int sum;
	vector<list<int>::iterator> iterators; 
	list<int>::iterator it;
   list<int> l;
   while( cin >> boxes >> instructions ){
		reversed = false;
		value = 0;
		cont++;
		iterators = vector<list<int>::iterator> ( boxes ); 
		l = list<int> ( boxes );
		for( it = l.begin(); it != l.end(); it++ ){
			iterators[ value ] = it;
			*it = ++value;
		}
      while( instructions ){
			cin >> command;
			if( command != 4 ){
			   cin >> x >> y; 
				sortBoxes( x, y, command, iterators, l, reversed );
			}
			else
				reversed = !reversed; 		
       instructions--;
      }
		sum = result( l, reversed );
		cout << "Case " << cont << ": " << sum << endl;
   }
	return 0;
}