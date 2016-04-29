#ifndef BST_TREE_H
#define BST_TREE_H
#include <string>
#include <sstream>
#include <cstddef> // For NULL
#include "bst_node.h"
using std::string;
using std::stringstream;

/**
 * The BSTree Class
 * Implements a binary search tree for integers
 */
class BSTree {
  public:
    /**
     * BSTree
     * Creates an empty BSTree structure
     */
    BSTree();

    /**
     * Insert
     * Inserts the specified value into the tree if not already inserted
     *
     * @param value - The value to insert
     * @return bool - True if the value was successfully inserted otherwise false
     */
    bool Insert(int value);

    /**
     * Clear
     * Removes all entries in the tree and frees the memory used by them
     */
    void Clear();

    /**
     * size
     * Returns the number of entries in this tree
     *
     * @return unsigned int - The number of entries in this tree
     */
    unsigned int size() const;

    /**
     * InOrder
     * Returns a the contents of this tree in a string in in-order progression
     *
     * @return string - A string representing the contents of this tree
     */
    string InOrder() const;

    /**
     * ~BSTree
     * Destroys the tree and frees the memory associated with it
     */
    ~BSTree();
  private:
    // Points to the root node of a binary search tree
    BSTNode* root_;
    // Holds the number of nodes in the tree
    unsigned int size_;
    // Function pointer define for child node accessors and mutators
    typedef BSTNode*& (BSTNode::*ChildFunc)();

    /**
     * Insert
     * Creates and inserts a new node into the tree with the specified value
     *
     * @param value - The value the new node will have
     * @param node - The node to being traversing the tree from
     * @return bool - True if the node was successfully inserted otherwise false
     */
    bool Insert(int value, BSTNode*& node);

    /**
     * Clear
     * Destroys the tree starting from the specified node
     *
     * @param node - The node to begin traversing from
     */
    void Clear(BSTNode*& node);

    /**
     * InOrder
     * Traverses the tree in-order and creates a string representing its values
     *
     * @param node - The node to begin traversing from
     */
    string InOrder(BSTNode* node) const;

    /**
     * Contains
     * Traverses the tree and determines if it contains a value
     *
     * @param value - The value to search for
     * @return bool - True if the value is found otherwise false
     */
    bool Contains(int value, BSTNode* node) const;
};

#endif