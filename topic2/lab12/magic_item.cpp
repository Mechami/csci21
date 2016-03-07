#include "magic_item.h"

// Since we don't have access to the name_ and value_ variables
// Call the constructor for our base class
// to initialize them for us
MagicItem::MagicItem(const string& name,
                     unsigned int value,
                     const string& description,
                     unsigned int mana_required)
          : Item(name, value),
            description_(description),
            mana_required_(mana_required) {
}

void MagicItem::set_description(const string& description) {
  this->description_ = description;
}

const string& MagicItem::description() const {
  return this->description_;
}

void MagicItem::set_mana_required(unsigned int mana_required) {
  this->mana_required_ = mana_required;
}

unsigned int MagicItem::mana_required() const {
  return this->mana_required_;
}

string MagicItem::ToString() const {
  stringstream result;
  result << this->Item::ToString();

  result << ", " << this->description_ << ", ";
  result << "requires " << this->mana_required_ << " mana";

  return result.str();
}

MagicItem::~MagicItem() {
  // Empty destructor that does nothing
}
