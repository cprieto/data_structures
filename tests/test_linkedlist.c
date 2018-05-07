#include <criterion/criterion.h>
#include "ds.h"

static NodePtr top;

void create_top_list() {
  top = lk_makeNode(1);
  top->next = lk_makeNode(2);
  top->next->next = lk_makeNode(3);
  top->next->next->next = lk_makeNode(4);
}

void tear_down() {
  top = NULL;
}

TestSuite(LinkedList, .init = create_top_list, .fini = tear_down);

Test(LinkedList, create) {
  NodePtr node = lk_makeNode(100);

  cr_assert(node != NULL);
  cr_assert(node->num == 100);
  cr_assert(node->next == NULL);
}

Test(LinkedList, length) {
  cr_assert(lk_length(top) == 4);
  cr_assert(lk_length(NULL) == 0);
}

Test(LinkedList, find) {
  cr_assert(lk_search(top, 2) == top->next);
  
  cr_assert(lk_search(top, 5) == NULL);
}

Test(LinkedList, last) {
  cr_assert(lk_last(top) != NULL);
  cr_assert(lk_last(top)->num == 4);

  cr_assert(lk_last(NULL) == NULL);
}

Test(LinkedList, get) {
  cr_assert(lk_get_at(top, 1) != NULL);
  cr_assert(lk_get_at(top, 1)->num == 2); 

  cr_assert(lk_get_at(NULL, 0) == NULL);
  cr_assert(lk_get_at(top, 5) == NULL);
}

Test(LinkedList, insert) {
  cr_assert(lk_insert_at(NULL, 0, 100) == false);
  cr_assert(lk_insert_at(&top, -1, 100) == false);
  cr_assert(lk_insert_at(&top, 10, 100) == false);

  // Insert at the beginning, 1, 2, 3, 4 -> 100, 1, 2, 3, 4
  cr_assert(lk_insert_at(&top, 0, 100) == true);
  cr_assert(top != NULL);
  cr_assert(top->num == 100);
  cr_assert(top->next != NULL);
  cr_assert(top->next->num == 1);
  
  // Insert at the middle, 100, 1, 2, 3, 4 -> 100, 200, 1, 2, 3, 4
  cr_assert(lk_insert_at(&top, 1, 200) == true);
  cr_assert(top->next != NULL);
  cr_assert(top->next->num == 200);
  cr_assert(top->next->next != NULL);
  cr_assert(top->next->next->num == 1);

  // Insert at the end, 100, 200, 1, 2, 3, 4 -> 100, 200, 1, 2, 3, 4, 300
  cr_assert(lk_insert_at(&top, 6, 300) == true);
  cr_assert(top->next->next->next->next->next->next != NULL);
  cr_assert(top->next->next->next->next->next->next->num == 300);
  cr_assert(top->next->next->next->next->next->next->next == NULL);
}

Test(LinkedList, remove) {
  cr_assert(lk_remove_at(&top, -1) == false);
  cr_assert(lk_remove_at(NULL, 0) == false);
  cr_assert(lk_remove_at(&top, 5) == false);

  // Remove node in the middle, 1, 3, 4
  cr_assert(lk_remove_at(&top, 1) == true);
  cr_assert(top->next != NULL);
  cr_assert(top->next->num == 3);

  // Remove node at the end, 1, 3
  cr_assert(lk_remove_at(&top, 2) == true);
  cr_assert(top->next->num == 3);
  cr_assert(top->next->next == NULL);

  // Remove node at the beginning, 3
  cr_assert(lk_remove_at(&top, 0) == true);
  cr_assert(top->next == NULL);
  cr_assert(top->num == 3);
}
