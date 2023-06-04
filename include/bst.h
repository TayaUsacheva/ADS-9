// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {
 private:
  struct Node {
    T value;
    int counter, dpth_Node;
    Node* left, * right;
  };
  Node* root;
  int dpth_Tree = -1;
  Node* addNode(Node* root, T value, int depth) {
    if (root == nullptr) {
      root = new Node;
      root->value = value;
      root->counter = 1;
      root->dpth_Node = depth;
      if (depth > dpth_Tree)
        dpth_Tree = depth;
      root->left = root->right = nullptr;
    } else if (value < root->value) {
      root->left = addNode(root->left, value, depth++);
    } else if (value > root->value) {
      root->right = addNode(root->right, value, depth++);
    } else {
      root->counter++;
    }
    return root;
  }

  int searchTree(Node* root, T value) {
    if (root == nullptr) {
      return -1;
    }
    while (true) {
      if (value > root->value) {
        root = root->right;
      } else if (value < root->value) {
        root = root->left;
      } else {
        return root->counter;
      }
    }
  }

 public:
  BST(): root(nullptr) {}
  void add(T value) {
    root = addNode(root, value, 0);
  }
  int depth() {
    return dpth_Tree;
  }
  int search(T value) {
    return searchTree(root, value);
  }
};
#endif  // INCLUDE_BST_H_
