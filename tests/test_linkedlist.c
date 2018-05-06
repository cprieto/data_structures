#include <criterion/criterion.h>
#include "ds.h"

Test(LinkedList, create) {
  NodePtr node = makeNode(100);

  cr_assert(node != NULL);
  cr_assert(node->num == 100);
  cr_assert(node->next == NULL);
}

Test(LinkedList, count_empty) {
  int total = count(NULL);
  cr_assert(total == 0);
}

Test(LinkedList, count) {
  const NodePtr top = makeNode(1);
  top->next = makeNode(2);
  top->next->next = makeNode(3);

  cr_assert(count(top) == 3);
}