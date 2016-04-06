#include "sl_list.h"
#include <iostream>

SLList::SLList() : head_(NULL), tail_(NULL), size_(0) {
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

  // Finally update the tail node
  tail_ = FindTail(head_);
}

void SLList::InsertTail(int contents) {
  // If we don't have anything in the list yet
  if (size_ < 1) {
    // Just insert it as the new head
    InsertHead(contents);
  }
  // Otherwise append it to the tail
  else {
    // Create the new node and append it to the list
    tail_->set_next_node(new SLNode(contents));
    // Update the tail pointer to point at the new tail
    tail_ = tail_->next_node();
    // Increment the list size
    size_ += 1;
  }
}

void SLList::RemoveHead() {
  // First make sure we have at least one node to work with
  if (head_) {
    // Copy the old head
    SLNode* node = head_;

    // Set the head to the next of kin
    head_ = head_->next_node();

    // Disassociate the old head from the next node to be on the safe side
    node->set_next_node(NULL);

    // Delete the old head
    delete node;

    // Decrement the size of the list
    size_ -= 1;
  }
}

void SLList::RemoveTail() {
  // If we have exactly one item
  if (size_ == 1) {
    // Just remove the head
    RemoveHead();
    // Then set the tail as null
    tail_ = NULL;
  }
  // Otherwise if we have more than one
  else if (size_ > 1) {
    // Find the node just before the tail
    SLNode* new_tail = FindPreTail(head_);
    // Detach the old tail from it
    new_tail->set_next_node(NULL);
    // Delete the old tail
    delete tail_;
    // Update the tail pointer to the new tail
    tail_ = new_tail;
    // Decrement the size of the list
    size_ -= 1;
  }
}

int SLList::GetHead() const {
  // Initialize the return value to zero
  int value = 0;

  // If we have a head node
  if (head_ != NULL) {
    // Get its contents
    value = head_->contents();
  }

  // Then return the value
  return value;
}

int SLList::GetTail() const {
  // Initialize the return value to zero
  int value = 0;

  // If we have a tail node
  if (tail_ != NULL) {
    // Get its contents
    value = tail_->contents();
  }

  // Then return the value
  return value;
}

void SLList::Clear() {
  // If we have any nodes
  while (size_ > 0) {
    // Remove them one-by-one
    RemoveHead();
  }

  // Then set the head to null
  head_ = NULL;

  // Then the tail
  tail_ = NULL;

  // Finally set the size back to zero just to be sure
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

SLNode* SLList::FindTail(SLNode* node) const {
  // Start at null
  SLNode* tail = NULL;

  // If the next node is null then we are at the tail
  if (node->next_node() == NULL) {
    tail = node;
  }
  // Otherwise keep moving
  else {
    tail = FindTail(node->next_node());
  }

  return tail;
}

SLNode* SLList::FindPreTail(SLNode* node) const {
  // If node is not null then get the next node
  SLNode* next = node? node->next_node() : NULL;
  // Set the return node to the current node
  SLNode* pretail = node;

  // If the next node and the next-next node are not null
  if (next && next->next_node()) {
    // Then advance the search by one
    pretail = FindPreTail(next);
  }

  // Otherwise just return node
  return pretail;
}
