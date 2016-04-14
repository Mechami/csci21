#ifndef DNODE_CXX
#define DNODE_CXX
#include "dnode.h"

template<typename T>
DNode<T>::DNode(const T& object) :
left(NULL), right(NULL), contents(object) {
  // Do nothing else
}

template<typename T>
DNode<T>::DNode(DNode<T>* leftNode, DNode<T>* rightNode, const T& object) :
left(leftNode), right(rightNode), contents(object) {
  if (left != NULL) {
    left->right = this;
  }

  if (right != NULL) {
    right->left = this;
  }
}

template<typename T>
const T& DNode<T>::Contents() const {
  return contents;
}

template<typename T>
T& DNode<T>::Contents() {
  return contents;
}

template<typename T>
DNode<T>::~DNode() {
  if (right != NULL) {
    right->left = this->left;
  }

  if (left != NULL) {
    left->right = this->right;
  }
}

/*********************
 * Private functions *
 *********************/

template<typename T>
bool DNode<T>::Insert(const T& object) {
  bool inserted = false;

  if (contents <= object) {
    ((right == NULL) || (right->contents > object))?
          (new DNode(this, right, object), inserted = true) :
          (inserted = right->Insert(object));
  }
  else if (contents > object) {
    ((left == NULL) || (left->contents < object))?
          (new DNode(left, this, object), inserted = true) :
          (inserted = left->Insert(object));
  }

  return inserted;
}

template<typename T>
DNode<T>* DNode<T>::FindNode(const T& object) {
  DNode<T>* query = NULL;

  if (contents == object) {
    query = this;
  }
  else if ((right != NULL) && (right->contents <= object)) {
    query = right->FindNode(object);
  }
  else if ((left != NULL) && (left->contents >= object)) {
    query = left->FindNode(object);
  }

  return query;
}

#endif
