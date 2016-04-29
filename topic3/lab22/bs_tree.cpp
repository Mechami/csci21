#include "bs_tree.h"

BSTree::BSTree() : root_(NULL), size_(0) {
  // Do Nothing
}

bool BSTree::Insert(int value) {
  bool inserted = false;

  if (!root_) {
    root_ = new BSTNode(value);
    size_ = 1;
    inserted = true;
  }
  else if (!Contains(value, root_)) {
    inserted = Insert(value, root_);
    size_++;
  }

  return inserted;
}

void BSTree::Clear() {
  if (root_ != NULL) {
    Clear(root_);
    root_ = NULL;
    size_ = 0;
  }
}

unsigned int BSTree::size() const {
  return size_;
}

string BSTree::InOrder() const {
  string tree_string = "";

  if (root_) {
    tree_string += InOrder(root_->left_child());

    stringstream ss; ss << root_->contents() << " ";
    tree_string += ss.str();

    tree_string += InOrder(root_->right_child());
  }

  return tree_string;
}

BSTree::~BSTree() {
  Clear();
}

bool BSTree::Insert(int value, BSTNode*& node) {
  bool inserted = false;

  if ((node != NULL) && (node->contents() != value)) {
    ChildFunc ChildNode = (value < node->contents())?
                           static_cast<ChildFunc>(&BSTNode::left_child) :
                           static_cast<ChildFunc>(&BSTNode::right_child);

    inserted = ((node->*ChildNode)() == NULL)?
               ((node->*ChildNode)() = new BSTNode(value), true) :
                Insert(value, (node->*ChildNode)());
  }

  return inserted;
}

void BSTree::Clear(BSTNode*& node) {
  if (node && node->left_child()) {
    Clear(node->left_child());
    delete node->left_child();
    node->set_left_child(NULL);
  }

  if (node && node->right_child()) {
    Clear(node->right_child());
    delete node->right_child();
    node->set_right_child(NULL);
  }

  if (node) {
    delete node;
    node = NULL;
  }
}

string BSTree::InOrder(BSTNode* node) const {
  string tree_string = "";

  if (node) {
    tree_string += InOrder(node->left_child());

    stringstream ss; ss << node->contents() << " ";
    tree_string += ss.str();

    tree_string += InOrder(node->right_child());
  }

  return tree_string;
}

bool BSTree::Contains(int value, BSTNode* node) const {
  bool found = false;
  int contents = (node != NULL)? node->contents() : 0;

  if (node != NULL) {
    found = (value == contents)? true :
    Contains(value, (value < contents)?
                    node->left_child() : node->right_child());
  }

  return found;
}
