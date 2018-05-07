#ifndef DS_H
#define DS_H
#include <stdbool.h>

typedef struct node {
  int num;
  struct node *next;
} Node, *NodePtr;

NodePtr ds_make_node(int value);
int ds_length(NodePtr top);
NodePtr ds_search(NodePtr top, const int value);
NodePtr ds_last(NodePtr top);
NodePtr ds_get_at(NodePtr top, const int index);
bool ds_insert_at(NodePtr *top, const int index, int value);
bool ds_remove_at(NodePtr *top, const int index);

#endif
