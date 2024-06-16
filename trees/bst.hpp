#pragma once
#include <functional>

template <typename T>
class bstree {
  struct node {
    T value;
    node* parent = nullptr;
    node* left = nullptr;
    node* right = nullptr;

    explicit node(T value) : value(value) {}

    ~node() {
      delete left;
      delete right;
    }

    void in_order(std::function<void(T)> action) {
      if (left != nullptr) {
        left->in_order(action);
      }
      action(value);
      if (right != nullptr) {
        right->in_order(action);
      }
    }
  };

  node* root;

  node* insert_node(node* current, T value) {
    if (current == nullptr) {
      current = new node(value);
      if (root == nullptr) {
        root = current;
      }
    } else if (value < current->value) {
      auto left_child = insert_node(current->left, value);
      current->left = left_child;
      left_child->parent = current;
    } else {
      auto right_child = insert_node(current->right, value);
      current->right = right_child;
      right_child->parent = current;
    }

    return current;
  }

 public:
  bstree() : root(nullptr) {}
  ~bstree() { delete root; }

  void insert(T value) { insert_node(root, value); }

  void foreach_in_order(std::function<void(T)> action) {
    if (root == nullptr)
      return;

    root->in_order(action);
  }
};
