#ifndef FOODITEM_H
#define FOODITEM_H

#include <string>
#include <sstream>
#include <iomanip>
#include "item.h"
using std::string;
using std::stringstream;
using std::fixed;
using std::setprecision;

/**
 * Class FoodItem
 * Represents a food item with value
 * Inherits from Item
 */
class FoodItem : public Item {
  public:
    // Setting parameter defaults for this constructor
    // allows it to double as a default constructor
    FoodItem(const string& name = "fooditem",
             unsigned int value = 0,
             unsigned int calories = 0,
             string unit_of_measure = "nounits",
             double units = 0.0);

    /**
     * @brief set_calories
     * Sets the amount of calories this food item contains
     * @param unsigned int calories - The calories this food item has
     */
    void set_calories(unsigned int calories);

    /**
     * @brief calories
     * Returns the amount of calories this food item contains
     * @return unsigned int - The amount of calories
     * in unsigned integer format
     */
    unsigned int calories() const;

    /**
     * @brief set_unit_of_measure
     * Sets the measurement unit for this food item
     * @param const string& unit_of_measure - A string representing
     * what unit of measurement this food item is using
     */
    void set_unit_of_measure(const string& unit_of_measure);

    /**
     * @brief unit_of_measure
     * Returns the measurement unit for this food item
     * @return const string& - A string representing the
     * unit of measurement this food item uses
     */
    const string& unit_of_measure() const;

    /**
     * @brief set_units
     * Sets the amount of units this food item represents
     * @param double units - The amount of units this item represents
     */
    void set_units(double units);

    /**
     * @brief units
     * Gets the amount of units this class represents
     * @return double - The amount of units this item represents
     * in double format
     */
    double units() const;

    /**
     * @brief ToString
     * String constructor for FoodItem
     * @return string - A string representing the class in
     * "name, $value, units unit_of_measure, calories" format
     */
    string ToString() const;

    // Virtual destructor that is undefined
    virtual ~FoodItem();
  private:
    // Holds a calorie count
    unsigned int calories_;
    // Holds the unit of measure
    string unit_of_measure_;
    // Holds a count of how many units we have
    double units_;
};

#endif
