#ifndef SLLIST_H
#define SLLIST_H
#include <string>
#include <sstream> // For ToString
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
     * Creates a new node and inserts it as th head of the list
     *
     * @param int - The contents the new head will have
     */
    void InsertHead(int contents);

    /**
     * RemoveHead
     * Removes the current head from the list if there is one
     */
     void RemoveHead();

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
    // stores the count of the number of nodes in the list
    unsigned int size_;
};

#endif
