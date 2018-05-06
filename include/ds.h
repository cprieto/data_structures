#ifndef DS_H
#define DS_H

typedef struct node {
  int num;
  struct node *next;
} Node, *NodePtr;

NodePtr makeNode(int);
int length(NodePtr);
NodePtr search(NodePtr, int);
NodePtr last(NodePtr);

#endif
