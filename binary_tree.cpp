#include <iostream>

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

class BinaryTree {
  public:
    BinaryTree();
    void printInOrderTraversal();
    void printPreOrderTraversal();
    void printPostOrderTraversal();
    void printInOrderTraversal(TreeNode *node);
    void printPreOrderTraversal(TreeNode *node);
    void printPostOrderTraversal(TreeNode *node);
    void makeTree();
  private:
    TreeNode *m_root;
};

BinaryTree::BinaryTree() {
  this->m_root = NULL;
}

void BinaryTree::printInOrderTraversal() {
  printInOrderTraversal(m_root);
}

void BinaryTree::printInOrderTraversal(TreeNode *node) {
  if(node != NULL) {
    printInOrderTraversal(node->left);
    std::cout << node->data << std::endl;
    printInOrderTraversal(node->right);
  }
}

void BinaryTree::printPreOrderTraversal() {
  printPreOrderTraversal(m_root);
}

void BinaryTree::printPreOrderTraversal(TreeNode *node) {
  if(node != NULL) {
    std::cout << node->data << std::endl;
    printPreOrderTraversal(node->left);
    printPreOrderTraversal(node->right);
  }
}

void BinaryTree::printPostOrderTraversal() {
  printPostOrderTraversal(m_root);
}

void BinaryTree::printPostOrderTraversal(TreeNode * node) {
  if(node != NULL) {
    printPostOrderTraversal(node->left);
    printPostOrderTraversal(node->right);
    std::cout << node->data << std::endl;
  }
}

void BinaryTree::makeTree() {
  m_root = new TreeNode(1);
  m_root->left = new TreeNode(2);
  m_root->right = new TreeNode(3);
 (m_root->left)->left = new TreeNode(4);
 (m_root->left)->right = new TreeNode(5);
 (m_root->right)->left = new TreeNode(6);
 (m_root->right)->right = new TreeNode(7);
}

int main(int argc, char *argv[]) {
  BinaryTree btree;
  btree.makeTree();
  std::cout << "InOrder Traversal" << std::endl;
  std::cout << "-------------------------------" << std::endl;
  btree.printInOrderTraversal();
  std::cout << "-------------------------------" << std::endl;

  std::cout << "PreOrder Traversal" << std::endl;
  std::cout << "-------------------------------" << std::endl;
  btree.printPreOrderTraversal();
  std::cout << "-------------------------------" << std::endl;

  std::cout << "PostOrder Traversal" << std::endl;
  std::cout << "-------------------------------" << std::endl;
  btree.printPostOrderTraversal();
  std::cout << "-------------------------------" << std::endl;
}
