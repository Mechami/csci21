#ifndef BST_NODE_H
#define BST_NODE_H
#include <cstddef> // For NULL

/**
 * BSTNode
 * A node for use in a Binary Search Tree
 */
class BSTNode {
  public:
    /**
     * BSTNode
     * Constructs a disconnected empty node
     */
    BSTNode();

    /**
     * BSTNode
     * Constructs a disconnected node with the specified contents
     *
     * @param int contents - The contents of this node
     */
    BSTNode(int contents);

    /**
     * set_contents
     * Sets the contents of this node to the specified contents
     *
     * @param int contents - The new contents this node will have
     */
    void set_contents(int contents);

    /**
     * contents (const)
     * Const-safe get method for this node's contents
     *
     * @return int - Copy of the contents of this node
     */
    int contents() const;

    /**
     * contents
     * Const-unsafe get method for this node's contents
     *
     * @return int& - Reference to this node's contents
     */
    int& contents();

    /**
     * set_left_child
     * Sets the left child of this node to the specified node
     *
     * @param BSTNode* - Pointer to the new child node
     */
    void set_left_child(BSTNode*);

    /**
     * set_right_child
     * Sets the right child of this node to the specified node
     *
     * @param BSTNode* - Pointer to the new child node
     */
    void set_right_child(BSTNode*);

    /**
     * left_child (const)
     * Const-safe get method for the left-child pointer
     *
     * @return BSTNode* - Copy of pointer to left-child
     */
    BSTNode* left_child() const;

    /**
     * left_child
     * Const-unsafe get method for the left-child pointer
     *
     * @return BSTNode*& - Reference to left-child pointer
     */
    BSTNode*& left_child();

    /**
     * right_child (const)
     * Const-safe get method for the right-child pointer
     *
     * @return BSTNode* - Copy of pointer to right-child
     */
    BSTNode* right_child() const;

    /**
     * right_child
     * Const-unsafe get method for the right-child pointer
     *
     * @return BSTNode*& - Reference to right-child pointer
     */
    BSTNode*& right_child();

    /**
     * ~BSTNode()
     * Disconnects this node from its children
     */
    virtual ~BSTNode();
  private:
    // points to a left child
    BSTNode* left_child_;
    // points to a right child
    BSTNode* right_child_;
    // used to store the data contents of a BSTNode
    int contents_;
};

#endif