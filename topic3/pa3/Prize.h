#ifndef PRIZE_H
#define PRIZE_H
#include <string>
using std::string;

/**
 * @brief The Prize class
 * Represents a prize
 */
class Prize {
  public:
    /**
     * @brief Prize
     * Default constructor
     * Initializes name to "NO NAME" and value to 0
     */
    Prize();

    /**
     * @brief Prize
     * Overloaded constructor for specifying name and value of new prize object
     *
     * @param name - String representing the name the prize will have
     * @param value - Non-negative integer representing the value of the prize
     */
    Prize(const string& name, unsigned value);

    /**
     * @brief ~Prize
     * Destructor for Prize that does absolutely nothing
     */
    virtual ~Prize();

    /**
     * @brief getPrizeName
     * Returns the name of the prize
     *
     * @return string - The name of the prize in the form of a string
     */
    const string& getPrizeName() const;

    /**
     * @brief setPrizeName
     * Sets the new name of the prize object
     *
     * @param new_name - A string containing the new name of the prize
     */
    void setPrizeName(const string& new_name);

    /**
     * @brief getPrizeValue
     * Returns a non-negative integer representing the value of the prize
     *
     * @return unsigned - The value of the prize as an unsigned integer
     */
    unsigned getPrizeValue() const;

    /**
     * @brief setPrizeValue
     * Sets the new value of the prize
     *
     * @param new_value - A non-negative integer representing the prize value
     */
    void setPrizeValue(unsigned new_value);

    /**
     * @brief operator ==
     * Equivalency operator overload
     * Accepts two Prize objects and compares their member objects for equivalency
     *
     * @param prizeOne - The first prize to compare against
     * @param prizeTwo - The second prize to compare against
     * @return bool - Whether or not both prize's member variables are equivalent
     */
    friend bool operator==(Prize prizeOne, Prize prizeTwo);
  private:
    string prizeName;
    unsigned int prizeValue;
};

#endif
