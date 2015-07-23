#ifndef NODE
#define NODE
#include "reunion.h"
template <class T>
class Node
{
public:
  Node();
  Node(T pinfo, Node * pnext=NULL);
  ~Node();
  T info;
  Node * next;
};

#endif // NODE

