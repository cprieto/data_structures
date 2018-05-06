#include <criterion/criterion.h>
#include "ds.h"

static NodePtr top;

void create_top_list() {
  top = makeNode(1);
  top->next = makeNode(2);
  top->next->next = makeNode(3);
}

void tear_down() {
  top = NULL;
}

TestSuite(LinkedList, .init = create_top_list, .fini = tear_down);

Test(LinkedList, create) {
  NodePtr node = makeNode(100);

  cr_assert(node != NULL);
  cr_assert(node->num == 100);
  cr_assert(node->next == NULL);
}

Test(LinkedList, count_empty) {
  int total = length(NULL);
  cr_assert(total == 0);
}


Test(LinkedList, count) {
  cr_assert(length(top) == 3);
}

Test(LinkedList, find) {
  cr_assert(search(top, 2) == top->next);
}

Test(LinkedList, find_not_found) {
  cr_assert(search(top, 5) == NULL);
}

Test(LinkedList, last) {
  cr_assert(last(top) != NULL);
  cr_assert(last(top)->num == 3);

  cr_assert(last(NULL) == NULL);
}

Test(LinkedList, get) {
  cr_assert(get(top, 1) != NULL);
  cr_assert(get(top, 1)->num == 2); 

  cr_assert(get(NULL, 0) == NULL);
  cr_assert(get(top, 5) == NULL);
}

Test(LinkedList, insert) {
  cr_assert(insert(top, 100, 1) == true);
  cr_assert(top->next->num == 100);
  cr_assert(top->next->next->num == 2);

  cr_assert(insert(top, 100, 5) == false);
}
