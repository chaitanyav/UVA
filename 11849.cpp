#include <iostream>

struct TreeNode {
  long int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(long int data, TreeNode *left = NULL, TreeNode *right = NULL) {
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
    bool contains(long int value);
    bool contains(TreeNode *node, long int value);
    long int getMin();
    long int getMin(TreeNode *root);
    void add(long int value);
    void add(TreeNode *&root, long int value);
    void remove(long int value);
    void remove(TreeNode *&node, long int value);
    void print();
    void print(TreeNode *node);

  private:
    TreeNode *m_root;
};

BinarySearchTree::BinarySearchTree() {
  this->m_root = NULL;
}

bool BinarySearchTree::contains(long int value) {
  return contains(m_root, value);
}

bool BinarySearchTree::contains(TreeNode *node, long int value) {
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

long int BinarySearchTree::getMin() {
  return getMin(m_root);
}

long int BinarySearchTree::getMin(TreeNode *node) {
  if(node->left == NULL) {
    return node->data;
  } else {
    return getMin(node->left);
  }
}

void BinarySearchTree::add(long int value) {
   add(m_root, value);
}

void BinarySearchTree::add(TreeNode *&node, long int value) {
  if(node == NULL) {
    node = new TreeNode(value);
  } else if(node->data > value) {
    add(node->left, value);
  } else {
    add(node->right, value);
  }
}

void BinarySearchTree::remove(long int value) {
  remove(m_root, value);
}

void BinarySearchTree::remove(TreeNode *&node, long int value) {
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
  BinarySearchTree *treep;

  long int m, n, temp;
  long long int matches;
  while(std::cin >> m >> n, (m != 0) && (n != 0)) {
    treep = new BinarySearchTree();
    matches = 0;
    while(m > 0) {
      std::cin >> temp;
      treep->add(temp);
      --m;
    }
    while(n > 0) {
      std::cin >> temp;
      if(treep->contains(temp)) {
        ++matches;
      }
      --n;
    }

    std::cout << matches << std::endl;
    delete treep;
  }

  return 0;
}
