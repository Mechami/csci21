#ifndef SLLIST_H
#define SLLIST_H
#include <string>
#include <sstream> // For ToString
#include <cstddef> // For NULL
#include "sl_node.h"
using std::string;
using std::stringstream;
using std::flush;

/**
 * SLlist
 * A class implementing a single-linked list
 */
class SLList {
  public:
    /**
     * SLList
     * Initializes member variables to sane default values
     */
    SLList();

    /**
     * InsertHead
     * Creates a new node and inserts it as the head of the list
     *
     * @param int - The contents the new head will have
     */
    void InsertHead(int contents);

    /**
     * InsertTail
     * Creates a new node and inserts it as the tail of the list
     */
    void InsertTail(int contents);

    /**
     * RemoveHead
     * Removes the current head from the list if there is one
     */
     void RemoveHead();

    /**
     * RemoveTail
     * Removes the current tail from the list if there is one
     */
    void RemoveTail();

    /**
     * GetHead
     * Returns the contents of the head node
     *
     * @return int - The contents of the head node or 0 if there is none
     */
    int GetHead() const;

    /**
     * GetTail
     * Returns the contents of the tail node
     *
     * @return int - The contents of the tail node or 0 if there is none
     */
    int GetTail() const;

    /**
     * Clear
     * Destroys all nodes in the list and frees their memory
     */
     void Clear();

    /**
     * size
     * Returns the current size of the list
     *
     * @return unsigned - The size of the list
     */
     unsigned int size() const;

    /**
     * ToString
     * Returns a string representation of the list
     *
     * @return string - A string in the form of "NUM1, NUM2, ..., LASTNUM" if
     * the list is populated otherwise an empty string
     */
     string ToString() const;

    virtual ~SLList();
  private:
    // points to the first node in a singly-linked list
    SLNode* head_;
    // points to the last node in a singly-linked list
    SLNode* tail_;
    // stores the count of the number of nodes in the list
    unsigned int size_;

    /**
     * FindTail
     * Returns the last node in the list
     *
     * @return SLNode* - The tail node
     */
    SLNode* FindTail(SLNode* node) const;

    /**
     * FindPreTail
     * Returns the next to last node in the list
     *
     * @return SLNode* - The node just before the tail node
     */
    SLNode* FindPreTail(SLNode* node) const;
};

#endif
