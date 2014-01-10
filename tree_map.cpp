#include <iostream>
#include <string>
#include <cassert>

struct TreeMapNode {
  std::string key;
  int value;
  TreeMapNode* left;
  TreeMapNode* right;

  TreeMapNode(std::string key, int value, TreeMapNode* left = NULL, TreeMapNode* right = NULL) {
    this->key = key;
    this->value = value;
    this->left = left;
    this->right = right;
  }

  bool isLeaf() {
    return (this->left == NULL) && (this->right == NULL);
  }
};

class TreeMap {
  public:
    TreeMap();
    void put(std::string key, int value);
    void put(TreeMapNode *&node, std::string key, int value);
    bool containsKey(std::string key) const;
    bool containsKey(TreeMapNode * node, std::string key) const;
    void remove(std::string key);
    void remove(TreeMapNode *&node, std::string key);
    TreeMapNode *getMin(TreeMapNode *node);
    int get(std::string key);
    int get(TreeMapNode *node, std::string key);
  private:
    TreeMapNode *m_root;
    int m_size;
};

TreeMap::TreeMap() {
  this->m_root= NULL;
  this->m_size = 0;
}

void TreeMap::put(std::string key, int value) {
  put(m_root, key, value);
}

void TreeMap::put(TreeMapNode *&node, std::string key, int value) {
  if(node == NULL) {
    node = new TreeMapNode(key, value);
    m_size++;
  } else if(node->key == key) {
    node->value = value;
  } else if(key < node->key) {
    put(node->left, key, value);
  } else if(key > node->key) {
    put(node->right, key, value);
  }
}

bool TreeMap::containsKey(std::string key) const {
  return containsKey(m_root, key);
}

bool TreeMap::containsKey(TreeMapNode *node, std::string key) const {
  if(node == NULL) {
    return false;
  } else if(key == node->key) {
    return true;
  } else if(key < node->key) {
    containsKey(node->left, key);
  } else {
    return containsKey(node->right, key);
  }
}

void TreeMap::remove(std::string key) {
  remove(m_root, key);
}

void TreeMap::remove(TreeMapNode *&node, std::string key) {
  if(node == NULL) {
  } else if(key == node->key) {
    if(node->isLeaf()) {
      node = NULL;
    } else if(node->right == NULL) {
      node = node->left;
    } else if(node->left == NULL) {
      node = node->right;
    } else {
      TreeMapNode *rightMinNode = getMin(node->right);
      node->key = rightMinNode->key;
      node->value = rightMinNode->value;
      remove(node->right, rightMinNode->key);
    }
    m_size--;
  } else if(key < node->key) {
    remove(node->left, key);
  } else {
    remove(node->right, key);
  }
}

TreeMapNode * TreeMap::getMin(TreeMapNode *node) {
  if(node->left == NULL) {
    return node;
  } else {
    return getMin(node->left);
  }
}

int TreeMap::get(std::string key) {
  return get(m_root, key);
}

int TreeMap::get(TreeMapNode *node, std::string key) {
  if(node == NULL) {
    return -1;
  } else if(node->key == key) {
    return node->value;
  } else if(key < node->key) {
    return get(node->left, key);
  } else {
    return get(node->right, key);
  }
}

int main(int argc, char *argv[]) {
  TreeMap *tree;
  tree = new TreeMap();
  assert(tree->get("a") == -1);
  assert(tree->containsKey("a") == false);
  tree->put("a", 1);
  assert(tree->containsKey("a"));
  assert(tree->get("a") == 1);
  tree->put("a", 2);
  assert(tree->get("a") == 2);
  tree->remove("a");
  assert(tree->containsKey("a") == false);
  tree->put("a", 1);
  tree->put("b", 2);
  tree->put("c", 3);
  tree->put("d", 4);
  tree->put("e", 0);
  assert(tree->containsKey("a"));
  assert(tree->containsKey("b"));
  assert(tree->containsKey("c"));
  assert(tree->containsKey("d"));
  assert(tree->containsKey("e"));
  tree->remove("a");
  tree->remove("b");
  tree->put("a", 1);
  tree->put("b", 2);
  assert(tree->get("e") == 0);
  assert(tree->get("d") == 4);
  assert(tree->get("a") == 1);
  assert(tree->get("b") == 2);
  return 0;
}
