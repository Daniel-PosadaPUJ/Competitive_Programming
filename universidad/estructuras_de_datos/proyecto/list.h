/*
Daniel Alejandro Posada Noguera
Miguel Ángel Padilla Rosero

Proyecto Final ( TAD List Prototipo )
Abril 29 de 2024

*/

#ifndef list_h
#define list_h

#include "node.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector> 

using namespace std;

typedef int Element;

class List {
private:
  Node *act;

  int listSize, nodeSize, nodeAmount;
  void interchange(List &);
public:
  List();
  List(int);
  List(vector<Element> &);
  List(const List &);
  void push_back(Element);
  void insert(Element, int);
  void remove(int);
  void set(int, Element);
  void push_front(Element);
  void append(List &);
  void resizeBlock(int);
  void print();
  Element at(int);
  Element getMax();
  int size();
  bool empty();
  bool contains(Element);
  vector<Element> getVector();
  bool operator==(List &);
  bool operator<(List &);
  Element operator[](int);
  List operator+(List &);
  static List addVectorOfLists(vector<List> &);
};

#endif