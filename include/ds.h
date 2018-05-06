#ifndef DS_H
#define DS_H
#include <stdbool.h>

typedef struct node {
  int num;
  struct node *next;
} Node, *NodePtr;

NodePtr makeNode(int);
int length(NodePtr);
NodePtr search(NodePtr, int);
NodePtr last(NodePtr);
NodePtr get(NodePtr, int);
bool insert(NodePtr, int, int);

#endif
