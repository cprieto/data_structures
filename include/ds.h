#ifndef DS_H
#define DS_H
#include <stdbool.h>

typedef struct node {
  int num;
  struct node *next;
} Node, *NodePtr;

NodePtr lk_makeNode(int);
int lk_length(NodePtr);
NodePtr lk_search(NodePtr, int);
NodePtr lk_last(NodePtr);
NodePtr lk_get_at(NodePtr, const int);
bool lk_insert_at(NodePtr*, const int, int);
bool lk_remove_at(NodePtr*, const int);

#endif
