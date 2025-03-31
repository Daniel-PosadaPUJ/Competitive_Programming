/* 
Solution B - Problem B (Data Structures)
Daniel Alejandro Posada Noguera 
Mayo 27 de 2024

*/

/*Análisis de Complejidad: 
La busqueda y asignación de valores en el mapa tiene complejidad o(log_m) donde m es el número de comandos, se requiere hacer 
por lo menos una busqueda o asignación por cada comando, luego:
 ---> Se concluye que la complejidad de la solución es T(n) E O(mlog_m) donde m es el número de comandos y n la población digitada <---
*/

#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<deque>

using namespace std; 

void initStructures( int amount, deque<pair<int,int>> &dq, map<int,int> &ma ){
   int i = 1;
   while( i <= amount ){
      dq.push_back( make_pair( i, 0 ) );
      ma[ i ] = 0;
      i++;
   }

}

int main(){
   int c, amount, cnt = 1, x, p;
   char command;
   map<int, int> m;
   pair<int, int> y;
   deque<pair<int, int>> q;
   cin >> p >> c; 
   while( p && c ){
      amount = ( p < c ) ? p : c;
      m.clear(); q.clear();
      initStructures( amount, q, m );
      cout << "Case " << cnt << ":" << endl;
      while( c-- ){
         cin >> command;
         if( command == 'N' ){
            y = q.front();
            q.pop_front();
            while( m[ y.first ] != y.second ){
               y = q.front();
               q.pop_front();
            }
            q.push_back( y );    
            cout << y.first << endl;
         }
         else{
            cin >> x;
            m.insert( make_pair( x, 0 ) );
            q.push_front( make_pair( x, ++m[ x ] ) );
         }
      }
      cnt++;
      cin >> p >> c;
   }
   return 0;
}
