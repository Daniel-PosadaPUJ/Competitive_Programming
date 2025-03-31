/* 
Solution B - Problem B (Data Structures)
Daniel Alejandro Posada Noguera 
Mayo 27 de 2024

*/

/*Análisis de commandplejidad: 
Dado que la mayor complejidad la presenta la estructura priority_queue con las operaciones push y pop que son O(log_n), 
y estas operaciones son ejecutadas en el peor de los casos n veces, podemos concluir que:
 ---> La complejidad de la solución es T(n) E O(nlog_n) donde n es la cantidad de elementos ingresados <---
*/

#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std; 


void clearAny( priority_queue<int, vector<int>> &a, stack<int> &b, queue<int> &c ){

   while( !a.empty() )
      a.pop();
   while( !b.empty() )
      b.pop();
   while( !c.empty() )
      c.pop();
}

void guess( int command, int x, priority_queue<int, vector<int>> &p, stack<int> &s, queue<int> &q, vector<bool> &decitions ){

   if( command == 1 ){
      if( decitions[ 0 ] )
         p.push( x );
      if( decitions[ 1 ] )
         s.push( x );
      if( decitions[ 2 ] )
         q.push( x );
   }
   else{
      if( decitions[ 0 ] ){
         decitions[ 0 ] = p.top() != x ? false : true;
         p.pop();
      }
      if( decitions[ 1 ] ){
         decitions[ 1 ] = s.top() != x ? false : true;
         s.pop();
      }
      if( decitions[ 2 ] ){
         decitions[ 2 ] = q.front() != x ? false : true;
         q.pop();
      }
   }
}

void classify( vector<bool> &decitions ){
   bool pflag = decitions[ 0 ], sflag = decitions[ 1 ], qflag = decitions[ 2 ]; 

   if( !pflag && sflag && !qflag )
      cout << "stack" << endl;
   else if( !pflag && !sflag && qflag )
      cout << "queue" << endl;
   else if( pflag && !sflag && !qflag )
      cout << "priority queue" << endl;
   else if( !pflag && !sflag && !qflag )
      cout << "impossible" << endl;
   else
      cout << "not sure" << endl;

}

int main(){
   int n, command, x;
   vector<bool> decitions; 
   priority_queue<int, vector<int>> p;
   stack<int> s;
   queue<int> q;

   while( cin >> n ){
      decitions = { true, true, true };
      clearAny( p, s, q );

      while( n-- ){
         cin >> command >> x;
         guess( command, x, p, s, q, decitions );
      }
      classify( decitions );
   }
   return 0;   
}

