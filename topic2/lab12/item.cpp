#include "item.h"

Item::Item(const string& name, unsigned int value)
     : name_(name), value_(value) {
  // Empty constructor as we don't have anything else to do
}

// Declare our parameter as const so we don't accidentally
// Overwrite someone else's string
void Item::set_name(const string& new_name) {
  this->name_ = new_name;
}

// Mark our return string reference as const
// so someone doesn't overwrite our name with something else
const string& Item::name() const {
  return this->name_;
}

// We don't need const here as we're given a copy of the new value
void Item::set_value(unsigned int new_value) {
  this->value_ = new_value;
}

// Likewise we don't need to return a const int as we're
// giving a copy of our value back
unsigned int Item::value() const {
  return this->value_;
}

// Unlike the Get functions we don't return a string reference
// If we did we'd be returning a reference to a temp string
// allocated on the stack frame of a function that has ended
string Item::ToString() const {
  stringstream result;

  result << this->name_ << ", $" << this->value_ << flush;

  return result.str();
}

Item::~Item() {
  // Empty destructor that does nothing
}
