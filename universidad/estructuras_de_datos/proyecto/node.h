/*
Daniel Alejandro Posada Noguera
Miguel Ángel Padilla Rosero

Proyecto Final ( TAD Node Prototipo )
Abril 29 de 2024

*/

#ifndef node_h
#define node_h

#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

typedef int Element;

class Node {
private:
  int n, amount;
  int start, end;
  vector<Element> block;
  Node *next;
  Node *prev;

  int getStart();
  int getEnd();
public:
  Node();
  Node(int);
  Node(Node &); 
  Element getData(int);
  Element pop_front();
  Element pop_back();
  Node *getNext();
  Node *getPrev();
  void setData(int, Element);
  void setNext(Node *);
  void setPrev(Node *);
  void push_back(Element);
  void insert(Element, int);
  void push_front(Element);
  void erase(int);
  void printPositions();
  int size();
  bool empty();
  int blockSize();
  bool contains(Element);
};

#endif