#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <sstream>
using std::string;
using std::stringstream;
using std::flush;

/**
 * Class Item
 * Base class for item objects
 */
class Item {
  public:
    // Setting parameter defaults for this constructor
    // allows it to double as a default constructor
    Item(const string& name = "item", unsigned int value = 0);

    /**
     * @brief set_name
     * Sets the name of the item
     * @param const string& - The new name for the item
     */
    void set_name(const string& new_name);

    /**
     * @brief name
     * Gets the current name of the item
     * @return const string& - A constant reference
     * to the item's name
     */
    const string& name() const;

    /**
     * @brief set_value
     * Sets the value of the item
     * @param unsigned int - The new value for the item
     */
    void set_value(unsigned int new_value);

    /**
     * @brief value
     * Gets the current value of the item
     * @return unsigned int - A copy of the item's value
     * in unsigned integer format
     */
    unsigned int value() const;

    /**
     * @brief ToString
     * String constructor for Item
     * @return string - A string representing the class in
     * "name, $value" format
     */
    string ToString() const;

    // Virtual destructor that is undefined
    virtual ~Item();
  private:
    // Holds the name of the item
    string name_;
    // Holds the value of the item
    unsigned int value_;
};

#endif
