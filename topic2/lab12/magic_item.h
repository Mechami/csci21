#ifndef MAGICITEM_H
#define MAGICITEM_H

#include <string>
#include <sstream>
#include "item.h"
using std::string;

/**
 * Class MagicItem
 * Represents a magical item with value
 * Inherits from Item
 */
class MagicItem : public Item {
  public:
    MagicItem(const string& name = "magicitem",
              unsigned int value = 0,
              const string& description = "no description",
              unsigned int mana_required = 0);

    void set_description(const string& description);
    const string& description() const;

    void set_mana_required(unsigned int mana_required);
    unsigned int mana_required() const;

    string ToString() const;

    virtual ~MagicItem();
  private:
    // Holds a description of the magic item
    string description_;
    // // Holds the amount of mana required to use the magic item
    unsigned int mana_required_;
};

#endif
