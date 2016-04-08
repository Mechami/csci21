#ifndef BOX_H
#define BOX_H
#include <string>
#include "Prize.h"
using std::string;

/**
 * @brief The Box class
 * A class that represents a prize box
 */
class Box {
  public:
    /**
     * @brief Box
     * Initializes the box with a number of 0 and a color of "NO COLOR"
     */
    Box();

    /**
     * @brief Box
     * Initializes the box to have a custom box number, color, and prize capacity
     * @param box_number - A non-negative integer representing the box number
     * @param box_color - A string representing the box color
     * @param prize_capacity - A non-negative integer specifying the prize capacity
     */
    Box(unsigned box_number, const string& box_color, unsigned prize_capacity);

    /**
     * @brief getBoxNumber
     * Returns the box number for this box
     *
     * @return unsigned int - A non-negative integer representing the box number
     */
    unsigned getBoxNumber() const;

    /**
     * @brief setBoxNumber
     * Sets the new box number for this box
     *
     * @param new_number - A non-negative integer representing the box number
     */
    void setBoxNumber(unsigned new_number);

    /**
     * @brief getBoxColor
     * Returns the color of this box
     *
     * @return string - A string representing the color of this box
     */
    const string& getBoxColor() const;

    /**
     * @brief setBoxColor
     * Sets the color of this box
     *
     * @param color - A string representing the color of this box
     */
    void setBoxColor(const string& color);

    /**
     * @brief getPrizeCapacity
     * Returns the prize capacity of this box
     *
     * @return unsigned int - A non-negative integer representing the prize capacity
     */
    unsigned getPrizeCapacity() const;

    /**
     * @brief getPrizeCount
     * Returns the amount of prizes in the box
     *
     * @return unsigned int - A non-negative integer representing the amount of prizes
     */
    unsigned getPrizeCount() const;

    /**
     * @brief addPrize
     * Adds a new prize to the box if there is room
     *
     * @param prize - The prize to add
     * @return bool - Whether or not the prize was added
     */
    bool addPrize(const Prize& prize);

    /**
     * @brief getPrize
     * Returns the prize at the specified index
     *
     * @param index - A non-negative integer specifying the index
     * @return Prize& - The prize at the specified index
     * or a generic prize if index was out of bounds
     */
    Prize& getPrize(unsigned index);

    /**
     * @brief removePrize
     * Removes the prize from the box at the index specified
     *
     * @param index - A non-negative integer specifying the index
     * @return Prize - The prize removed if one was found
     * Or a generic prize if index was out of bounds
     * Or a prize at the specified index did not exist
     */
    Prize removePrize(unsigned index);

   /**
    * ~Box
    * Destructor for Box
    * Safely deletes all stored prizes
    */
    ~Box();
  private:
    unsigned boxNumber;
    string boxColor;
    Prize scratch;
    Prize** prizes;
    unsigned prizeCapacity;
    unsigned prizeCount;
};

#endif
