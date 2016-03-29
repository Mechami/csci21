#ifndef SLNODE_H
#define SLNODE_H

class SLNode {
  public:
    /**
     * SLNode
     * Default constructor that initializes all member variables to 0 or null
     */
    SLNode();

    /**
     * SLNode
     * Overloaded constructor that takes a parameter for the node contents
     *
     * @param contents - The contents the node shall have
     */
    SLNode(int contents);

    /**
     * set_contents
     * Changes the contents of this node to the parameter specified
     *
     * @param new_contents - The new contents this node shall have
     */
    void set_contents(int new_contents);

    /**
     * contents
     * Gets the current contents of this node
     *
     * @return int - The contents of this node
     */
    int contents() const;

    /**
     * set_next_node
     * Sets the next node this node will point to
     *
     * @param next_node - The node this node shall point to
     */
    void set_next_node(SLNode* next_node);

    /**
     * next_node
     * Gets the current node this node is pointing to
     *
     * @return SLNode* - The node this node points to
     */
    SLNode* next_node() const;

    /**
     * ~SLNode
     *
     * Destructor for this node
     * Currently does nothing
     */
    ~SLNode();
  private:
    // points to the next node in a singly-linked list
    SLNode* next_node_;
    // stores the data contents of a SLNode
    int contents_;
};

#endif
