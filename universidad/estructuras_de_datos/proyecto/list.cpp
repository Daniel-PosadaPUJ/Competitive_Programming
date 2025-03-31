/*
Daniel Alejandro Posada Noguera
Miguel Ángel Padilla Rosero

Proyecto Final ( TAD List Implementación )
Abril 29 de 2024

*/

#include "list.h"

using namespace std;

typedef int Element;

//T(n) = O(1)
List::List(){
  act = NULL;
  nodeSize = 20;
  listSize = 0;
  nodeAmount = 0;
}
//T(n) = O(1)
List::List( int s ){
  act = NULL;
  listSize = 0;
  nodeSize = s;
  nodeAmount = 0;
}
//T(n) = O(n), con n = v.size()
List::List( vector<Element> &v ){
  int i = 0, k = 1;
  act = NULL;
  nodeSize = 10, listSize = v.size(); 
  Node *n = new Node( nodeSize ), *last = NULL;

  while( i < listSize ){
    n->push_back( v[ i ] );
    if( i == k * nodeSize - 1 || i == listSize - 1 ){
      if ( act == NULL ){
        act = n;
        last = n;
        act->setNext( n );
        act->setPrev( last );
      }
      else{
        last->setNext( n );
        n->setPrev( last );
        n->setNext( act );
        act->setPrev( n );
        last = n;
      }
      nodeAmount++;
      n = new Node( nodeSize );
      k++;
    }
    i++;
  }
}
//T(n) = O(n), donde n es la cantidad de elementos de la lista. 
List::List( const List &l ){
  act = NULL;
  nodeAmount = l.nodeAmount;
  nodeSize = l.nodeSize, listSize = l.listSize;
  int i;
  Node *tmp = l.act, *last = tmp->getPrev();
  
  for( i = 0; i < nodeAmount; i++ ){
    Node *n = new Node( *tmp ); 
    if ( act == NULL ){
      act = n;
      last = n;
      act->setNext( n );
      act->setPrev( last );
    }
    else{
      last->setNext( n );
      n->setPrev( last );
      n->setNext( act );
      act->setPrev( n );
      last = n;
    } 
  }
}
//T(n) E O(1)
void List::push_back( Element e ){
  Node *n = new Node( nodeSize ), *last;
  if ( act == NULL ){
    act = n;
    n->push_back( e );
    act->setNext( n );
    act->setPrev( n );
    nodeAmount++;
  } 
  else{
    last = act->getPrev();
    if ( last->size() < nodeSize )
      last->push_back( e );
    else{
      n->push_back( e );
      last->setNext( n );
      n->setPrev( last );
      n->setNext( act );
      act->setPrev( n );
      nodeAmount++;
    }
  }
  listSize++;
}
//T(n) E O(1)
void List::push_front( Element e ){
  Node *n = new Node( nodeSize ), *last;
  if ( act == NULL ){
    act = n;
    n->push_front( e );
    act->setNext( n );
    act->setPrev( n );
    nodeAmount++;
  } 
  else{
    last = act->getPrev();
    if ( act->size() < nodeSize )
      act->push_front( e );
    else{
      n->push_front( e );
      last->setNext( n );
      n->setPrev( last );
      n->setNext( act );
      act->setPrev( n );
      act = n;
      nodeAmount++;
    }
  }
  listSize++;
}
//T(n) E O(1)
int List::size(){ 
  return listSize;
}
//T(n) E O(1)
bool List::empty(){
  return !listSize; 
}
//T(n) E O(n/m), donde n es la cantidad de elementos de la lista y m es el tamaño del bloque.
Element List::at( int pos ){ 
  Node *tmp = act;
  int i, falency = nodeSize - act->size(), posNode = ( pos + falency ) / nodeSize;
  int posInNode = ( pos + falency ) % nodeSize;
  Element dato;
  
  if ( pos < listSize / 2 ){ 
    for ( i = 0; i < posNode; i++ )
      tmp = tmp->getNext();
  }
  else{
    for ( i = 0; i < nodeAmount - posNode; i++ )
      tmp = tmp->getPrev();  
  }
  dato = tmp->getData( posInNode );
  return dato;
}
//T(n) E O(n/m), donde n es la cantidad de elementos de la lista y m es el tamaño del bloque.
void List::set( int pos, Element e ){
  Node *tmp = act;
  int i, falency = nodeSize - act->size(), posNode = ( pos + falency ) / nodeSize;
  int posInNode = ( pos + falency ) % nodeSize;

  if ( pos < listSize / 2 ){ 
    for ( i = 0; i < posNode; i++ )
      tmp = tmp->getNext();
  }
  else{
    for ( i = 0; i < nodeAmount - posNode; i++ ) 
      tmp = tmp->getPrev();  
  }
  tmp->setData( posInNode , e );
}
// T(n) E O(1)
Element List::getMax(){ 
  Node *tmp = act;
  int i, j, maxElement = tmp->getData( 0 );

  for( i = 0; i < nodeAmount; i++ ){
    for( j = 0; j < tmp->size(); j++ ){
      if( maxElement < tmp->getData( j ) )
        maxElement = tmp-> getData( j );
    }
  }
  return maxElement;
}
//T(n) = O(n)
bool List::contains( Element e ){ 
  bool ans = false;
  int i = 0;
  Node *tmp = act;

  while( i < nodeAmount && !ans ){
    if( tmp->contains( e ) )
      ans = true;
    tmp = tmp->getNext();
    i++;
  }
  return ans;
}
//T(n) E O(n)
vector<Element> List::getVector(){
  vector<Element> v(listSize);
  Node *tmp = act, *last = act->getPrev();
  int i, j, k = 0;
  
  for( i = 0; i < nodeAmount; i++ ){
    for( j = 0; j < tmp->size(); j++ ){
      v[ k ] = tmp->getData( j );
      k++;
    }
    tmp = tmp->getNext();
  }
  return v;
}
//T(n) E O(n/m)
int List::operator[]( int pos ){
  return at( pos );
}
//T(n) E O(n)
void List::print(){
  Node *tmp = act;
  int i, j;
  
  for( i = 0; i < nodeAmount; i++ ){
    for( j = 0; j < tmp->size(); j++ ){
      if( i != nodeAmount - 1 || j != tmp->size() - 1 )
        cout << tmp->getData( j ) << " ";
      else
        cout << tmp->getData( j ) << endl;
    }
    tmp = tmp->getNext();
  }
  cout << endl;
}
//T(n) E O(n) 
bool List::operator<( List &l ){
  bool ans = true; 
  Node *tmp = act, *tmp2 = l.act;
  int i = 0, j = 0, k = 0, size1 = tmp->size(), size2 = tmp2->size();
  if( listSize > l.listSize )
    ans = false;
  else{
    while( k < listSize && ans ){
      if( i == size1 ){
        tmp = tmp->getNext();
        size1 = tmp->size();
        i = 0;
      }
      if( j == size2 ){
        tmp2 = tmp2->getNext();
        size2 = tmp2->size();
        j = 0;
      }
      if( tmp->getData( i ) > tmp2->getData( j ) )
        ans = false;
      i++; k++; j++;    
    }
  }
  return ans; 
}
//T(n) E O(n)
bool List::operator==( List &l ){
  bool ans = true; 
  Node *tmp = act, *tmp2 = l.act;
  int i = 0, j = 0, k = 0, size1 = tmp->size(), size2 = tmp2->size();
  if( listSize != l.listSize )
    ans = false;
  else{
    while( k < listSize && ans ){
      if( i == size1 ){
        tmp = tmp->getNext();
        size1 = tmp->size();
        i = 0;
      }
      if( j == size2 ){
        tmp2 = tmp2->getNext();
        size2 = tmp2->size();
        j = 0;
      }
      if( tmp->getData( i ) != tmp2->getData( j ) )
        ans = false;
      i++; k++; j++;    
    }
  }
  return ans; 
}
//T(n) E O(n) donde n es el tamaño de la lista recibida.
void List::append( List &l ){
  int i, j;
  Node *tmp = l.act;
  
  for( i = 0; i < l.nodeAmount; i++ ){
    for( j = 0; j < tmp->size(); j++ )
       push_back( tmp->getData( j ) );
    tmp = tmp->getNext();
  }
}
//T(n) E O(n) donde n es el tamaño de la lista recibida.
void List::interchange( List &l ){
  int i, j, m;
  Node *tmp = l.act;
  
  for( i = 0; i < l.nodeAmount; i++ ){
    m = tmp->size();
    for( j = 0; j < m; j++ )
       push_back( tmp->pop_front() );
    tmp = tmp->getNext();
    delete tmp->getPrev(); 
  }
}
//T(n) E O(n) donde n es el tamaño total de la lista resultante (la suma de las dos listas).
List List::operator+( List &l ){
  List ans( *this ); 
  ans.append( l );
  return ans; 
}
//T(n) E O(n) donde n es el tamaño total de la lista resultante (la suma de todas las listas)
List List::addVectorOfLists( vector<List> &v ){
  List ans( v[ 0 ] );
  int i, n = v.size();
  for( i = 1; i < n; i++ )
    ans.append( v[ i ] );
  return ans; 
}
//T(n) E O(n) donde n es el tamaño de la lista actual
void List::resizeBlock( int s ){
  List l( s );
  l.interchange( *this );
  act = l.act;
}
//T(n) E O(n/m + m/2) donde n es el tamaño de la lista y m el tamaño de los bloques.
void List::insert( Element e, int pos ){
  Node *tmp = act, *auxNode = new Node(nodeSize);
  Element aux;
  int i, falency = nodeSize - act->size(), posNode = ( pos + falency ) / nodeSize;
  int posInNode = ( pos + falency ) % nodeSize;

  if ( pos < listSize / 2 ){ 
    if( tmp->size() == nodeSize ){
      push_front( tmp->getData( 0 ) );
      tmp->erase( 0 );
    }
    for ( i = 0; i < posNode; i++ ){
      auxNode = tmp->getNext();
      aux = auxNode->pop_front();
      tmp->push_back( aux );
      tmp = tmp->getNext();
    }
  }
  else{
    tmp = tmp->getPrev();
    if( tmp->size() == nodeSize ){
      push_back( tmp->getData( tmp->size() - 1 ) );
      tmp->erase( tmp->size() - 1 );
    }
    for ( i = 0; i < nodeAmount - posNode - 1; i++ ){
      auxNode = tmp->getPrev();
      aux = auxNode->pop_back();
      tmp->push_front( aux );
      tmp = tmp->getPrev();
    }  
  }
  tmp->insert( e, posInNode );
  listSize++;
}
//T(n) E O(n/m + m/2) donde n es el tamaño de la lista y m el tamaño de los bloques.
void List::remove( int pos ){
  Node *tmp = act, *auxNode = new Node(nodeSize);
  Element aux, aux2;
  bool flag = false;
  int i, falency = nodeSize - act->size(), posNode = ( pos + falency ) / nodeSize;
  int posInNode = ( pos + falency ) % nodeSize;

  if ( pos < listSize / 2 ){ 
    if( posNode == 0 )
      tmp->erase( posInNode );
    else{
      aux = tmp->pop_back();
      auxNode = tmp->getNext();
      if( tmp->empty() ){
        act = auxNode;
        auxNode->setPrev( tmp->getPrev() );
        tmp->getPrev()->setNext( auxNode );
        nodeAmount--;
        delete tmp; 
      }
      tmp = auxNode;
      for( i = 0; i < posNode - 1; i++ ){
        aux2 = tmp->pop_back();
        tmp->push_front( aux );
        aux = aux2;
        tmp = tmp->getNext();
      }
      tmp->erase( posInNode );
      tmp->push_front( aux );
    }
  }
  else{
    tmp = tmp->getPrev();
    if( posNode == nodeAmount - 1 )
      tmp->erase( posInNode );
    else{
      aux = tmp->pop_front();
      auxNode = tmp->getPrev();
      if( tmp->empty() ){
        auxNode->setNext( tmp->getNext() );
        tmp->getNext()->setPrev( auxNode );
        nodeAmount--;
        delete tmp; 
      }
      tmp = auxNode;
      for( i = 0; i < nodeAmount - posNode - 2; i++ ){
        aux2 = tmp->pop_front();
        tmp->push_back( aux );
        aux = aux2;
        tmp = tmp->getPrev();
      }
      tmp->erase( posInNode );
      tmp->push_back( aux );
    }
  }
  listSize--;
}

