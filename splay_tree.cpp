#include <iostream>
#include <functional>
#include <cassert>

template <typename ValueType>
struct Node {
  Node *left;
  Node *right;
  Node *parent;
  ValueType key;

  Node(ValueType key, Node *left = NULL, Node *right = NULL, Node *parent = NULL) {
    this->key = key;
    this->left = left;
    this->right = right;
    this->parent = parent;
  }
};


template <typename ValueType, typename Comp>
class SplayTree {
  private:
    Comp comp;
    Node<ValueType> *root;
    unsigned long int pSize;
    void leftRotate(Node<ValueType>* node);
    void rightRotate(Node<ValueType>* node);
    void splay(Node<ValueType> *node);
    void replace(Node<ValueType> *node1, Node<ValueType>* node2);
    Node<ValueType>* subTreeMinimum(Node<ValueType>* node);
    Node<ValueType>* subTreeMaximum(Node<ValueType>* node);
  public:
    SplayTree();
    void insert(const ValueType &key);
    Node<ValueType>* find(const ValueType &key);
    ValueType minimum();
    ValueType maximum();
    void erase(const ValueType &key);
    bool empty() const;
    unsigned long int size() const;
};

template <typename ValueType, typename Comp>
SplayTree<ValueType, Comp>::SplayTree() {
  this->root = NULL;
  this->pSize = 0;
}

template <typename ValueType, typename Comp>
void SplayTree<ValueType, Comp>::leftRotate(Node<ValueType> *node) {
  Node<ValueType> *right = node->right;
  node->right = right->left;
  if(right->left != NULL) {
    right->left->parent = node;
  }
  right->parent = node->parent;
  if(node->parent == NULL) {
    root = right;
  } else if(node == node->parent->left) {
    node->parent->left = right;
  } else {
    node->parent->right = right;
  }

  right->left = node;
  node->parent = right;
}

template <typename ValueType, typename Comp>
void SplayTree<ValueType, Comp>::rightRotate(Node<ValueType> *node) {
  Node<ValueType> *left = node->left;
  node->left = left->right;
  if(left->right != NULL) {
    left->right->parent = node;
  }
  left->parent = node->parent;
  if(node->parent == NULL) {
    root = left;
  } else if(node == node->parent->left) {
    node->parent->left = left;
  } else {
    node->parent->right = left;
  }
  left->right = node;
  node->parent = left;
}

template <typename ValueType, typename Comp>
void SplayTree<ValueType, Comp>::splay(Node<ValueType>* node) {
  while(node->parent != NULL) {
    if(node->parent->parent == NULL) {
      if(node->parent->left == node) {
        rightRotate(node->parent);
      } else {
        leftRotate(node->parent);
      }
    } else if(node->parent->left == node && node->parent->parent->left == node->parent) {
      rightRotate(node->parent->parent);
      rightRotate(node->parent);
    } else if(node->parent->right == node && node->parent->parent->right == node->parent) {
      leftRotate(node->parent->parent);
      leftRotate(node->parent);
    } else if(node->parent->left == node && node->parent->parent->left == node->parent) {
      rightRotate(node->parent);
      leftRotate(node->parent);
    } else {
      leftRotate(node->parent);
      rightRotate(node->parent);
    }
  }
}

template <typename ValueType, typename Comp>
void SplayTree<ValueType, Comp>::replace(Node<ValueType> *node1, Node<ValueType> *node2) {
  if(node1->parent == NULL) {
    root = node2;
  } else if(node1 == node1->parent->left) {
    node1->parent->left = node2;
  } else {
    node1->parent->right = node2;
  }
  if(node2 != NULL) {
    node2->parent = node1->parent;
  }
}

template <typename ValueType, typename Comp>
Node<ValueType>* SplayTree<ValueType, Comp>::subTreeMinimum(Node<ValueType> *node) {
  while(node->left != NULL) {
    node = node->left;
  }

  return node;
}

template <typename ValueType, typename Comp>
Node<ValueType>* SplayTree<ValueType, Comp>::subTreeMaximum(Node<ValueType> *node) {
  while(node->right != NULL) {
    node = node->right;
  }

  return node;
}

template <typename ValueType, typename Comp>
Node<ValueType>* SplayTree<ValueType, Comp>::find(const ValueType &key) {
  Node<ValueType> *node = root;
  while(node != NULL) {
    if(comp(node->key, key)) {
      node = node->right;
    } else if(comp(key, node->key)) {
      node = node->left;
    } else {
      return node;
    }
  }

  return NULL;
}


template <typename ValueType, typename Comp>
void SplayTree<ValueType, Comp>::insert(const ValueType &key) {
  Node<ValueType>* node = root;
  Node<ValueType>* parent = NULL;

  while(node != NULL) {
    parent = node;
    if(comp(node->key, key)) {
      node = node->right;
    } else {
      node = node->left;
    }
  }

  node = new Node<ValueType>(key);
  node->parent = parent;

  if(parent == NULL) {
    root = node;
  } else if(comp(parent->key, node->key)) {
    parent->right = node;
  } else {
    parent->left = node;
  }

  splay(node);
  pSize++;
}

template <typename ValueType, typename Comp>
ValueType SplayTree<ValueType, Comp>::minimum() {
  Node<ValueType>* node = subTreeMinimum(root);
  return node->key;
}

template <typename ValueType, typename Comp>
ValueType SplayTree<ValueType, Comp>::maximum() {
  Node<ValueType>* node = subTreeMaximum(root);
  return node->key;
}

template <typename ValueType, typename Comp>
bool SplayTree<ValueType, Comp>::empty() const {
  return root == NULL;
}

template <typename ValueType, typename Comp>
unsigned long int SplayTree<ValueType, Comp>::size() const {
  return pSize;
}

template <typename ValueType, typename Comp>
void SplayTree<ValueType, Comp>::erase(const ValueType &key) {
  Node<ValueType> *node = find(key);
  if(node == NULL) {
    return;
  }

  splay(node);
  if(node->left == NULL) {
    replace(node, node->right);
  } else if(node->right == NULL) {
    replace(node, node->left);
  } else {
    Node<ValueType> *min = subTreeMinimum(node->right);
    if(min->parent != node) {
      replace(min, min->right);
      min->right = node->right;
      min->right->parent = min;
    }
    replace(node, min);
    min->left = node->left;
    min->left->parent = min;
  }

  delete node;
  pSize--;
}

int main(int argc, char *argv[]) {
  SplayTree<int, std::less<int> > sp;
  assert(sp.empty());
  sp.insert(1);
  assert(sp.find(1) != NULL);
  sp.insert(2);
  assert(sp.find(2) != NULL);
  sp.insert(3);
  assert(sp.find(3) != NULL);
  sp.erase(3);
  assert(sp.find(3) == NULL);
  assert(sp.empty() == false);
  assert(sp.size() == 2UL);
  sp.insert(4);
  sp.insert(5);
  sp.insert(6);
  sp.insert(7);
  sp.insert(8);
  assert(sp.size() == 7UL);
  assert(sp.minimum() == 1);
  assert(sp.maximum() == 8);
  return 0;
}
