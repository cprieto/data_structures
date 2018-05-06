#include <stdlib.h>
#include "ds.h"

NodePtr makeNode(int num) {
  NodePtr node = (Node *)malloc(sizeof(Node));
  node->num = num;
  node->next = NULL;
  return node;
}

int length(NodePtr node) {
  if (node == NULL) { return 0; }
  int count = 1;
  while (node->next != NULL) {
    node = node->next;
    count++;
  }
  return count;
}

NodePtr search(NodePtr node, int num) {
  while (node != NULL) {
    if (node->num == num) { return node; }
    node = node->next;
  }
  return NULL;
}

NodePtr last(NodePtr node) {
  while (node != NULL) {
    if (node->next == NULL) return node;
    node = node->next;
  }
  return NULL;
}
