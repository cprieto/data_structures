#include <catch2/catch_all.hpp>

#include "bst.hpp"

TEST_CASE("In-order transversal", "[btree]") {
  bstree<int> tree;

  tree.insert(5);
  tree.insert(3);
  tree.insert(7);
  tree.insert(2);
  tree.insert(4);
  tree.insert(6);
  tree.insert(8);

  std::vector<int> result;
  tree.foreach_in_order(
      [&result](int elem) -> void { result.push_back(elem); });

  std::vector<int> expected = {2, 3, 4, 5, 6, 7, 8};
  REQUIRE(result == expected);
}
