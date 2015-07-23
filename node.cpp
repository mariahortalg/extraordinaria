#include "node.h"

template <class T>
Node<T>::Node(){
  this->next=NULL;
}

template <class T>
Node<T>::Node(T pinfo, Node *pnext){
  this->info=pinfo;
  this->next=pnext;
}

template <class T>
Node<T>::~Node(){
}



