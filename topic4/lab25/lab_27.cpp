/*
 * Name        : lab_27.cpp
 * Author      : Philip Muzzall
 * Description : Using the STL
 */
#include "lab_27.h"

void TreasureChest::AddItem(const Item& item_to_add) {
 chest_.push_back(item_to_add);
}

void TreasureChest::InsertItem(const Item& item_to_add, unsigned int position) {
  if (position < chest_.size()) {
    // insert() doesn't take a integer for a position
    // so we get an iterator to the beginning and use the offset from there
    chest_.insert(chest_.begin() + position, item_to_add);
  }
  else {
    chest_.push_back(item_to_add);
  }
}

const Item* TreasureChest::GetItem(unsigned int position) const {
  // If the position is valid then return a pointer to the item
  // otherwise NULL
  return  ((position < chest_.size())? &chest_[position] : NULL);
}

Item TreasureChest::RemoveItem(unsigned int position) {
  // Default-construct an empty Item
  Item removed_item;

  if (position < chest_.size()) {
    removed_item = chest_[position];
    // Once again erase() does not accept an integer argument
    // so start at the beginning iterator and advance by position
    chest_.erase(chest_.begin() + position);
  }
  else {
    // Throw an error if it's an invalid position
    throw string("ERROR: Remove at invalid position");
  }

  return removed_item;
}

void TreasureChest::Clear() {
  chest_.clear();
}

bool TreasureChest::Empty() const {
  return chest_.empty();
}

unsigned int TreasureChest::GetSize() const {
  return chest_.size();
}

void TreasureChest::SortByName() {
  // Use stable sort to prevent identical items from getting moved
  stable_sort(chest_.begin(), chest_.end(), CompareItemsByName);
}

void TreasureChest::SortByValue() {
  // Likewise with SortByName
  stable_sort(chest_.begin(), chest_.end(), CompareItemsByValue);
}

void TreasureChest::SortByQuantity() {
  // Likewise with SortByName
  stable_sort(chest_.begin(), chest_.end(), CompareItemsByQuantity);
}

ostream& operator<<(ostream& outs, const TreasureChest& src) {
  // For each item in the list
  for (unsigned index = 0; index < src.GetSize(); index++) {
    // If the item is not at the end of the list append a comma
    outs << *src.GetItem(index) << ((index < (src.GetSize() - 1))? ", " : "") << flush;
  }

  // If the list is empty
  if (src.Empty()) {
    // make it known
    outs << "Chest Empty!" << flush;
  }

  return outs;
}

string TreasureChest::ToString() {
  stringstream ss;

  // Use the << operator to print this chest to the stream
  ss << *this << flush;
  return ss.str();
}

bool CompareItemsByName(const Item& lsrc, const Item& rsrc) {
  return (lsrc.name_ < rsrc.name_);
}

bool CompareItemsByValue(const Item& lsrc, const Item& rsrc) {
  return (lsrc.value_ < rsrc.value_);
}

bool CompareItemsByQuantity(const Item& lsrc, const Item& rsrc) {
  return (lsrc.quantity_ < rsrc.quantity_);
}
