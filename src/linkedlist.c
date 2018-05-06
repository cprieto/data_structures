#include <stdlib.h>
#include "ds.h"

NodePtr makeNode(int num) {
  NodePtr node = (Node *)malloc(sizeof(Node));
  node->num = num;
  node->next = NULL;
  return node;
}

int count(NodePtr node) {
  if (node == NULL) { return 0; }
  int count = 1;
  while (node->next != NULL) {
    node = node->next;
    count++;
  }
  return count;
}
