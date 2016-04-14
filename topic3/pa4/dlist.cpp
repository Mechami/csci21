#ifndef DLIST_CXX
#define DLIST_CXX
#include "dlist.h"

template<typename T>
DList<T>::DList() : head(NULL), tail(NULL), size(0ul) {
  // Do nothing else
}

template<typename T>
bool DList<T>::insert(const T& object) {
  bool inserted = false;

  if (head != NULL) {
    inserted = head->Insert(object);
  }
  else {
    head = new DNode<T>(object);
    inserted = true;
  }

  if (tail == NULL || tail->contents <= object) {
    tail = FindHighest(head);
  }

  if (head->contents >= object) {
    head = FindLowest(head);
  }

  size += static_cast<unsigned long>(inserted);
  return inserted;
}

template<typename T>
void DList<T>::pushFront(const T& newContents) {
  if (size < 1) {
    insert(newContents);
  }
  else {
    head = new DNode<T>(NULL, FindLowest(head), newContents);
  }

  size += 1;
}

template<typename T>
void DList<T>::pushBack(const T& newContents) {
  if (size < 1) {
    insert(newContents);
  }
  else {
    tail = new DNode<T>(FindHighest(head), NULL, newContents);
  }

  size += 1;
}

template<typename T>
const T& DList<T>::getFront() const {
  if (size < 1) {
    throw "LIST EMPTY";
  }

  return head->contents;
}

template<typename T>
const T& DList<T>::getBack() const {
  if (size < 1) {
    throw "LIST EMPTY";
  }

  return tail->contents;
}

template<typename T>
bool DList<T>::get(const T& target) const {
  return (FindNode(head, target) != NULL);
}

template<typename T>
bool DList<T>::removeFirst(const T& object) {
  bool removed = false;
  DNode<T>* node = head->FindNode(object);

  if (node != NULL) {
    delete node;
    removed = true;
  }

  size -= static_cast<unsigned long>(removed);
  return removed;
}

template<typename T>
bool DList<T>::removeAll(const T& object) {
  bool removed = false;

  DNode<T>* node = FindLowest(head);
  removed = Remove(node, object);

  if (size < 1) {
    head = NULL;
    tail = NULL;
  }

  return removed;
}

template<typename T>
void DList<T>::popFront() {
  DNode<T>* node = NULL;

  if (size > 0) {
    node = FindLowest(head);
  }

  if (node != NULL) {
    head = node->right;
    delete node;
    size -= 1;
  }

  if (size < 1) {
    head = NULL;
    tail = NULL;
  }
}

template<typename T>
void DList<T>::popBack() {
  DNode<T>* node = NULL;

  if (size > 0) {
    node = FindHighest(head);
  }

  if (node != NULL) {
    tail = node->left;
    delete node;
    size -= 1;
  }

  if (size < 1) {
    head = NULL;
    tail = NULL;
  }
}

template<typename T>
void DList<T>::clear() {
  DNode<T>* node = (size > 0)? FindLowest(head) : NULL;

  while (node != NULL) {
    DNode<T>* old_node = node;
    node = node->right;

    delete old_node;
    size -= 1;
  }

  if (size < 1) {
    head = NULL;
    tail = NULL;
  }
}

template<typename T>
unsigned long DList<T>::length() const {
  return size;
}

template<typename T>
string DList<T>::to_string(bool show_index) const {
  stringstream output;
  unsigned index = 0;

  DNode<T>* node = (size > 0)? FindLowest(head) : NULL;

  while (node != NULL) {
    stringstream temp;
    show_index? (temp << "[" << ++index << "] ") : "";
    output << temp.str() << node->contents << std::endl;
    node = node->right;
  }

  return output.str();
}

template<typename T>
const T& DList<T>::operator[](unsigned long index) const {
  DNode<T>* node = head;

  while (index > 0) {
    node = node->right;
    index -= 1;
  }

  return node->contents;
}

template<typename T>
DList<T>::~DList() {
  clear();
}

template<typename T>
DNode<T>* DList<T>::FindNode(DNode<T>* node, const T& object) const {
  DNode<T>* query = NULL;

  if (node != NULL) {
    query = ((node->contents == object)?
               node : FindNode((node->contents <= object)?
                                node->right : node->left,
                               object));
  }

  return query;
}

template<typename T>
DNode<T>* DList<T>::FindLowest(DNode<T>* node) const {
  return ((node->left == NULL)? node : FindLowest(node->left));
}

template<typename T>
DNode<T>* DList<T>::FindHighest(DNode<T>* node) const {
  return ((node->right == NULL)? node : FindHighest(node->right));
}

template<typename T>
bool DList<T>::Remove(DNode<T>* node, const T& object) {
  bool removed = false;

  if (node != NULL) {
    removed = Remove(node->right, object);
  }

  if ((node != NULL) && (node->contents == object)) {
    removed = true;
    delete node;
    size -= 1;
  }

  return removed;
}

#endif
