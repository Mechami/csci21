#include "sl_node.h"

SLNode::SLNode() : next_node_(NULL), contents_(0) {
  // Do nothing else
}

SLNode::SLNode(int contents) : next_node_(NULL), contents_(contents) {
  // Do nothing else
}

void SLNode::set_contents(int new_contents) {
  contents_ = new_contents;
}

int SLNode::contents() const {
  return contents_;
}

void SLNode::set_next_node(SLNode* next_node) {
  next_node_ = next_node;
}

SLNode* SLNode::next_node() const {
  return next_node_;
}

SLNode::~SLNode() {
  // Do nothing
}
