#ifndef DS_H
#define DS_H

typedef struct node {
  int num;
  struct node *next;
} Node, *NodePtr;

NodePtr makeNode(int);
int count(NodePtr);

#endif
