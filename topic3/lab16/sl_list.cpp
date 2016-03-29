#include "sl_list.h"

SLList::SLList() : head_(static_cast<SLNode*>(0)), size_(0) {
  // Do nothing else
}

SLList::~SLList() {
  // Free our memory as we're about to kick the bucket
  Clear();
}

void SLList::InsertHead(int contents) {
  // Create our new node
  SLNode* new_node = new SLNode(contents);

  // If we already have a head set it as the next node in the list
  if (head_) {
    new_node->set_next_node(head_);
  }

  // Set the new node as the head
  head_ = new_node;

  // Increment the size of the list
  size_ += 1;
}

void SLList::RemoveHead() {
  // First make sure we have at least one node to work with
  if (head_) {

    // Get the next node in line
    SLNode* node = head_->next_node();

    // Disassociate the head from the next node to be on the safe side
    head_->set_next_node(static_cast<SLNode*>(0));

    // Delete the old head
    delete head_;

    // Set the next of kin as the new head
    head_ = node;

    // Decrement the size of the list
    size_ -= 1;
  }
}

void SLList::Clear() {
  // Start at the head node
  SLNode* node = head_;

  // Create a pointer to the old node
  while (SLNode* old_node = node) {

    // Then advance to the next node
    node = node->next_node();

    // Then delete the old node
    delete old_node;
  }

  // Set the head to null
  head_ = static_cast<SLNode*>(0);

  // Reset the size back to zero
  size_ = 0;
}

unsigned int SLList::size() const {
  return size_;
}

string SLList::ToString() const {
  // Create a string stream to hold our string
  stringstream result("");

  // First we make an anchor variable for the loop
  SLNode* node = head_;

  // Then we make a pointer for the previous node
  while (SLNode* old_node = node) {

    // Advance the node by one
    node = node->next_node();

    // Print out the old node contents
    // Then tack on the comma-space if we have another node
    result << old_node->contents() << (node? ", " : "") << flush;
  }

  // Then return the compiled string
  return result.str();
}
