#include <stdlib.h>
#include <stdio.h>
#include "ds.h"

NodePtr lk_makeNode(int num) {
  NodePtr node = (Node *)malloc(sizeof(Node));
  node->num = num;
  node->next = NULL;
  return node;
}

int lk_length(NodePtr node) {
  if (node == NULL) { return 0; }
  int count = 1;
  while (node->next != NULL) {
    node = node->next;
    count++;
  }
  return count;
}

NodePtr lk_search(NodePtr node, int num) {
  while (node != NULL) {
    if (node->num == num) { return node; }
    node = node->next;
  }
  return NULL;
}

NodePtr lk_last(NodePtr node) {
  while (node != NULL) {
    if (node->next == NULL) return node;
    node = node->next;
  }
  return NULL;
}

NodePtr lk_get_at(NodePtr top, const int index) {
  for (int x = 0; x < index; x++) {
    if (top == NULL) { return NULL; }
    top = top->next;
  }
  return top;
}

bool lk_insert_at(NodePtr *top, const int index, int value) {
  if (index < 0 || top == NULL || *top == NULL) { return false; }
    
  NodePtr node = lk_makeNode(value);
  if (index == 0) {
    node->next = *top;
    *top = node;
  } else {
    NodePtr prev = *top;
    for (int i = 0; i < index - 1; i++) {
      if (prev == NULL) { return false; }
      prev = prev->next;
    }
    node->next = prev->next;
    prev->next = node;
  }
  return true;
}

bool lk_remove_at(NodePtr *top, const int index) {
  if (index < 0 || top == NULL || *top == NULL) {
    return false;
  }
  
  NodePtr node = *top;
  if (index == 0) {
    *top = node->next;
  } else {
    NodePtr prev;
    for (int n = 0; n < index; n++) {
      if (node == NULL) { return false; }
      if (n == index - 1) { prev = node; }
      
      node = node->next;
    }
    prev->next = node->next;
  }
  
  free(node);
  return true;
}