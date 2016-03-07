#include "food_item.h"

// Since we don't have access to the name_ and value_ variables
// Call the constructor for our base class
// to initialize them for us
FoodItem::FoodItem(const string& name, unsigned int value,
                   unsigned int calories, string unit_of_measure,
                   double units)
         : Item(name, value), calories_(calories),
           unit_of_measure_(unit_of_measure), units_(units) {
}

void FoodItem::set_calories(unsigned int calories) {
  this->calories_ = calories;
}

unsigned int FoodItem::calories() const {
  return this->calories_;
}

void FoodItem::set_unit_of_measure(const string& unit_of_measure) {
  this->unit_of_measure_ = unit_of_measure;
}

const string& FoodItem::unit_of_measure() const {
  return this->unit_of_measure_;
}

void FoodItem::set_units(double units) {
  this->units_ = units;
}

double FoodItem::units() const {
  return this->units_;
}

// Since units_ is a double we'll use the fixed and secprecision
// io manipulators to ensure it stays at 2 decimal places
string FoodItem::ToString() const {
  stringstream result;
  result << this->Item::ToString();
  result << ", ";
  result << fixed << setprecision(2) << this->units_;
  result << " " << this-> unit_of_measure_;
  result << ", " << this->calories_ << " calories";

  return result.str();
}

FoodItem::~FoodItem() {
  // Empty destructor that does nothing
}
