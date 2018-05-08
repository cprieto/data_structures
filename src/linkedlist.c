#include <stdlib.h>
#include <stdio.h>
#include "ds.h"

NodePtr ds_make_node(int num) {
  NodePtr node = (Node *)malloc(sizeof(Node));
  node->num = num;
  node->next = NULL;
  return node;
}

int ds_length(NodePtr node) {
  if (node == NULL) { return 0; }
  int count = 1;
  while (node->next != NULL) {
    node = node->next;
    count++;
  }
  return count;
}

NodePtr ds_search(NodePtr node, int num) {
  while (node != NULL) {
    if (node->num == num) { return node; }
    node = node->next;
  }
  return NULL;
}

NodePtr ds_last(NodePtr node) {
  while (node != NULL) {
    if (node->next == NULL) return node;
    node = node->next;
  }
  return NULL;
}

NodePtr ds_get_at(NodePtr top, const int index) {
  for (int x = 0; x < index; x++) {
    if (top == NULL) { return NULL; }
    top = top->next;
  }
  return top;
}

bool ds_insert_at(NodePtr *top, const int index, int value) {
  if (index < 0 || top == NULL || *top == NULL) { return false; }
    
  NodePtr node = ds_make_node(value);
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

bool ds_remove_at(NodePtr *top, const int index) {
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

bool ds_sorted_insert(NodePtr *top, int value) {
  if (top == NULL) { return false; }

  NodePtr node = ds_make_node(value);
  NodePtr prev = NULL;
  NodePtr current = *top;
  while (current != NULL && current->num < value) {
    prev = current;
    current = current->next;
  }
  node->next = current;

  if (prev != NULL) { 
    prev->next = node; 
  } else {
    *top = node;
  }

  return true;
}
