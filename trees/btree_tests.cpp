#include <catch2/catch_all.hpp>

#include "bst.hpp"

TEST_CASE("In-order transversal", "[bstree]") {
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

TEST_CASE("contains", "[bstree]") {
    auto tree = new bstree<int>();

    tree->insert(5);
    tree->insert(3);
    tree->insert(7);
    tree->insert(2);
    tree->insert(4);
    tree->insert(6);
    tree->insert(8);

    REQUIRE(tree->contains(2));
    REQUIRE_FALSE(tree->contains(10));
}

TEST_CASE("minimum", "[bstree]") {
    auto tree = new bstree<int>();

    auto result = tree->min();
    REQUIRE_FALSE(result.has_value());

    tree->insert(5);

    result = tree->min();
    REQUIRE(result.has_value());
    REQUIRE(result.value() == 5);

    tree->insert(3);
    tree->insert(7);
    tree->insert(2);
    tree->insert(4);
    tree->insert(6);
    tree->insert(8);

    result = tree->min();
    REQUIRE(result.has_value());
    REQUIRE(result.value() == 2);
}

TEST_CASE("maximum", "[bstree]") {
    auto tree = new bstree<int>();

    auto result = tree->max();
    REQUIRE_FALSE(result.has_value());

    tree->insert(5);

    result = tree->max();
    REQUIRE(result.has_value());
    REQUIRE(result.value() == 5);

    tree->insert(3);
    tree->insert(7);
    tree->insert(2);
    tree->insert(4);
    tree->insert(6);
    tree->insert(8);

    result = tree->max();
    REQUIRE(result.has_value());
    REQUIRE(result.value() == 8);
}
