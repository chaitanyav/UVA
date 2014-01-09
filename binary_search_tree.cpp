#include <iostream>
#include <cassert>

struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int data, TreeNode *left = NULL, TreeNode *right = NULL) {
    this->data = data;
    this->left = left;
    this->right = right;
  }

  bool isLeaf() {
    return (this->left == NULL) && (this->right == NULL);
  }
};

class BinarySearchTree {
  public:
    BinarySearchTree();
    bool contains(int value);
    bool contains(TreeNode *node, int value);
    int getMin();
    int getMin(TreeNode *root);
    void add(int value);
    void add(TreeNode *&root, int value);
    void remove(int value);
    void remove(TreeNode *&node, int value);
    void print();
    void print(TreeNode *node);

  private:
    TreeNode *m_root;
};

BinarySearchTree::BinarySearchTree() {
  this->m_root = NULL;
}

bool BinarySearchTree::contains(int value) {
  return contains(m_root, value);
}

bool BinarySearchTree::contains(TreeNode *node, int value) {
  if(node == NULL) {
    return false;
  } else if(node->data == value) {
    return true;
  } else if(node->data > value) {
    return contains(node->left, value);
  } else {
    return contains(node->right, value);
  }
}

int BinarySearchTree::getMin() {
  return getMin(m_root);
}

int BinarySearchTree::getMin(TreeNode *node) {
  if(node->left == NULL) {
    return node->data;
  } else {
    return getMin(node->left);
  }
}

void BinarySearchTree::add(int value) {
   add(m_root, value);
}

void BinarySearchTree::add(TreeNode *&node, int value) {
  if(node == NULL) {
    node = new TreeNode(value);
  } else if(node->data > value) {
    add(node->left, value);
  } else {
    add(node->right, value);
  }
}

void BinarySearchTree::remove(int value) {
  remove(m_root, value);
}

void BinarySearchTree::remove(TreeNode *&node, int value) {
  if(node == NULL) {
    return;
  } else if(node->data > value) {
    remove(node->left, value);
  } else if(node->data < value) {
    remove(node->right, value);
  } else {
    if(node->right == NULL) {
      TreeNode *trash = node;
      node = node->left;
      delete trash;
    } else if(node->left == NULL) {
      TreeNode *trash = node;
      node = node->right;
      delete trash;
    } else {
      node->data = getMin(node->right);
      remove(node->right, node->data);
    }
  }
}

void BinarySearchTree::print() {
  print(m_root);
}

void BinarySearchTree::print(TreeNode *node) {
  if(node != NULL) {
    print(node->left);
    std::cout << node->data << std::endl;
    print(node->right);
  }
}

int main(int argc, char *argv[]) {
  BinarySearchTree tree;

  // test node
  TreeNode *nodep;
  nodep = new TreeNode(1);
  assert(nodep->data == 1);
  assert(nodep->left == NULL);
  assert(nodep->right == NULL);
  assert(nodep->isLeaf());

  // test tree
  assert(tree.contains(1) == false);
  tree.add(1);
  assert(tree.contains(1));
  tree.add(0);
  assert(tree.contains(0));
  tree.add(2);
  assert(tree.contains(2));
  tree.add(3);
  assert(tree.contains(3));
  tree.add(4);
  assert(tree.contains(4));
  tree.print();

  tree.remove(1);
  assert(tree.contains(1) == false);
  assert(tree.contains(0));
  tree.remove(2);
  assert(tree.contains(2) == false);
  assert(tree.contains(3));
  assert(tree.contains(4));

  tree.print();

  return 0;
}
