/*
Daniel Alejandro Posada Noguera
Miguel Ángel Padilla Rosero

Proyecto Final ( TAD Node Implementación )
Abril 29 de 2024

*/

#include "node.h"
#include <iostream>

using namespace std;

typedef int Element;

//T(n) E O(1)
Node::Node(){         
  n = 20; 
  amount = 0;
  block = vector<int> (n);
  start = n;
  end = -1;
  next = NULL;
  prev = NULL;
}
//T(n) E O(1)
Node::Node( int n ){         
  this->n = n; 
  amount = 0;
  block = vector<int> (n);
  start = n;
  end = -1;
  next = NULL;
  prev = NULL;
}
//T(n) E O(n) donde n es el tamaño del vector.
Node::Node( Node &t ){
  n = (t.block).size();
  amount = t.size();
  start = t.getStart();
  end = t.getEnd();
  block = vector<int> (n);
  block = t.block; 
  next = NULL;
  prev = NULL;
}
//T(n) E O(1)
Element Node::getData( int pos ){
   return block[ ( start + pos ) % n ];
}
//T(n) E O(1)
Node * Node::getNext(){
   return next;
  }
//T(n) E O(1)
Node * Node::getPrev(){
  return prev; 
}
//T(n) E O(1)
void Node::setData( int pos, Element e ){
  block[ ( start + pos ) % n ] = e;
}
//T(n) E O(1)
void Node::setNext( Node* n ){
  next = n;
}
//T(n) E O(1)
void Node::setPrev( Node* n ){
  prev = n;
}
//T(n) E O(1)
void Node::push_back( Element e ){
    end = ( end + 1 ) % n;
    block[ end ] = e;
    amount++;
}
//T(n) E O(1) 
void Node::push_front( Element e ){
  start = ( start - 1 + n ) % n;
  block[ start ] = e;
  amount++;
}
//T(n) E O(1)
Element Node::pop_front(){
  Element ans = block[ start ];
  block[ start ] = 0;
  start = ( start + 1 ) % n;
  amount--;
  return ans;
}
//T(n) E O(1)
Element Node::pop_back(){
  Element ans = block[ end ];
  block[ end ] = 0;
  end = ( end - 1 + n ) % n;
  amount--;
  return ans; 
}
//T(n) E O(n) [ O(1) en el mejor caso, que es cuando se inserta en los extremos ]
void Node::insert( Element e, int pos ){ 
  int j = 0, realPos = ( start + pos ) % n, distanceToSt = ( realPos - start + n ) % n, distanceToEnd = ( end - realPos + n ) % n; 
  bool direction = distanceToSt < distanceToEnd, flag = amount == 1; 
  
  if( direction || flag ){
    realPos = ( start + pos - 1 ) % n;
    while( j < distanceToSt ){ 
      block[ ( start + j - 1 ) % n ] = block[ ( start + j ) % n ]; 
      j++;
    } 
    start = ( start - 1 + n ) % n;
  }
  else{
    while( j < distanceToEnd + 1 ){ 
      block[ ( end - j + 1 + n ) % n ] = block[ ( end - j + n ) % n ]; 
      j++;
    }
    end = ( end + 1 ) % n;
  }
  block[ realPos ] = e;

  amount++;
}
//T(n) E O(n) [ O(1) en el mejor caso, que es cuando se borra en los extremos ]
void Node::erase( int pos ){
  int j = 0, realPos = ( start + pos ) % n, distanceToSt = ( realPos - start + n ) % n, distanceToEnd = ( end - realPos + n ) % n;
  bool direction = distanceToSt < distanceToEnd, flag = amount == 1; 

  if( flag ){
    start = n;
    end = -1;
    block[ realPos ] = 0;
  }
  else if( direction ){
    while( j < distanceToSt ){ 
      block[ ( realPos - j + n ) % n ] = block[ ( realPos - j - 1 + n ) % n ]; 
      j++;
    } 
    block[ start ] = 0;
    start = ( start + 1 ) % n;
  }
  else{
    while( j < distanceToEnd ){ 
      block[ ( realPos + j ) % n ] = block[ ( realPos + j + 1 ) % n ]; 
      j++;
    }
    block[ end ] = 0;
    end = ( end - 1 ) % n;
  }

  amount--;
}
//T(n) E O(n) donde n es la cantidad de elementos válidos del nodo.
void Node::printPositions(){
  int i;
  cout << "Values:    ";
  for( i = 0; i < amount; i++ )
    cout << block[ ( start + i ) % n ] << " ";
  cout << endl;

  cout << "Positions: ";
  for( i = 0; i < amount; i++ )
    cout << ( start + i ) % n << " ";
  cout << endl;

}
//T(n) E O(1)
int Node::size(){
  return amount; 
}
//T(n) E O(1)
int Node::blockSize(){
  return block.size();
}
//T(n) E O(1)
bool Node::empty(){
  return !amount;
}
//T(n) E O(n) donde n es la cantidad de elementos válidos del nodo.
bool Node::contains( Element e ){ 
  int i = 0, flag = false;
  while( i < amount && !flag ){
    if( block[ ( start + i ) % n ] == e )
      flag = true;
    i++;
  }
  return flag;
}
//T(n) E O(1)
int Node::getStart(){
    return start;
}
//T(n) E O(1)
int Node::getEnd(){
    return end;
}

