/*
Proyecto Estructuras de Datos 2024-1
Archivo main de prueba
Mayo 13 de 2024

 */


#include <cstdio>
#include <vector>
#include <list>
#include <deque>
#include "list.h"

int main(){
  int n, o, i, v, m, suma, t, casos;
  List l1, l2, l3, l4(40), l5, l6, l7, l8, l9;
  vector<int> vec;
  vector<List> vecList;

  scanf("%d", &casos);
  while(casos--){
    l1 = List(100);
    l2 = List(120);
    l3 = List();
    l4 = List(40);
    l5 = List();
    l6 = List();
    l7 = List();
    l8 = List();
    l9 = List();
    vec.clear();
    vecList.clear();
    
   scanf("%d", &n);
   for(i = 0; i < n; ++i){
     scanf("%d %d", &o, &v);
     
     if(o == 1){
       l1.push_back(v);
       l4.push_front(v);
     }
     else{
       l1.push_front(v);
       l4.push_back(v);
     }
   }

   scanf("%d", &n);
   for(i = 0; i < n; ++i){
     scanf("%d", &v);
     vec.push_back(v);
   }

   l2 = List(vec);
   l3 = List(l2);
   
   scanf("%d", &m);
   for(i = 0; i < m; ++i){
     scanf("%d %d", &o, &v);
     if(o == 1){
       l3.push_back(v);
       l4.push_front(v);
     }
     else{
       l3.push_front(v);
       l4.push_back(v);
     }
   }

   printf("Lista l1:\n");
   l1.print();
   printf("Lista l2:\n");
   l2.print();
   printf("Lista l3:\n");
   l3.print();
   printf("Lista l4:\n");
   l4.print();

   scanf("%d", &m);
   for(i = 0; i < m; ++i){
     scanf("%d", &o);
     if(o == 1)
       l4.remove(0);
     else
       l4.remove(l4.size() - 1);
   }

   printf("Lista l4:\n");
   l4.print();

   i = suma = 0;
   while(i < l1.size()){
     suma += l1.at(i);
     ++i;
   }

   printf("Suma = %d\n", suma);

   i = suma = 0;
   while(i < l2.size()){
     suma += l2[i];
     ++i;
   }

   printf("Suma = %d\n", suma);
   
   scanf("%d", &m);
   for(i = 0; i < m; ++i){
     scanf("%d %d %d", &o, &t, &v);
     if(o == 1)
       l3.set(t, v);
     else
       l3.insert(v, t);
   }

   printf("Lista l3:\n");
   l3.print();

   vec = {2, 4, 6, 8, 10, 24};
   l5 = List(vec);
   l6.push_back(2);
   l6.push_back(4);
   l6.push_back(6);
   l6.push_back(8);
   l6.push_back(10);
   l6.push_back(24);

   printf("Lista l5:\n");
   l5.print();
   printf("Lista l6:\n");
   l6.print();

   if(l5 == l6)
     printf("l5 y l6 son iguales\n");
   else
     printf("l5 y l6 NO son iguales\n");

   if(l3 == l2)
     printf("l3 y l2 son iguales\n");
   else
     printf("l3 y l2 NO son iguales\n");

   l5.remove(0);
   l5.remove(3);
   l5.remove(l5.size() - 1);
   l5.remove(l5.size() - 1);
   l5.remove(l5.size() - 1);
   l5.remove(l5.size() - 1);
   
   if(l5.empty())
     printf("La lista l5 está vacía\n");
   else
     printf("La lista l5 NO está vacía\n");

   l5.append(l1);
   l5.append(l2);
   l2.append(l3);

   printf("Lista l1:\n");
   l1.print();
   printf("Lista l5:\n");
   l5.print();
   printf("Lista l2:\n");
   l2.print();
   printf("Lista l3:\n");
   l3.print();

   l7 = l1 + l6;
   printf("Lista l7:\n");
   l7.print();
   l7 = l2 + l5;
   printf("Lista l7:\n");
   l7.print();

   vec = l7.getVector();
   printf("Vector vec:\n");
   for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
     printf("%d ", *it);
   printf("\n");

   printf("El máximo de la lista l1 es %d\n", l1.getMax());
   printf("El máximo de la lista l7 es %d\n", l7.getMax());
   printf("El máximo de la lista l3 es %d\n", l3.getMax());

   scanf("%d", &m);
   i = 0;
   while(i < m){
     scanf("%d", &v);
     if(l7.contains(v))
       printf("La lista l7 contiene el valor %d\n", v);
     else
       printf("La lista l7 NO contiene el valor %d\n", v);
     ++i;
   }

   l1.resizeBlock(50);
   printf("Lista l1:\n");
   l1.print();
   l1.resizeBlock(30);
   printf("Lista l1:\n");
   l1.print();
   l1.resizeBlock(100);
   printf("Lista l1:\n");
   l1.print();

   l7.resizeBlock(90);
   printf("Lista l7:\n");
   l7.print();
   l7.resizeBlock(45);
   printf("Lista l7:\n");
   l7.print();
   
   vecList.push_back(l1);
   vecList.push_back(l2);
   vecList.push_back(l3);
   vecList.push_back(l4);
   vecList.push_back(l5);
   vecList.push_back(l6);
   vecList.push_back(l7);
   vecList.push_back(l8);

   l9 = List::addVectorOfLists(vecList);
   printf("Lista l9:\n");
   l9.print();

   while(l1.size() > 0)
      l1.remove(0);
  }
  
  return 0;
}
