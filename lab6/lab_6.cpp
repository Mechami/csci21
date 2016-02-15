/*
 * Name        : lab_6.cpp
 * Author      : Philip Muzzall
 * Description : Working with Arrays
 */

// Include cstdlib here since we're not supposed to modify the header
#include <cstdlib>
#include "lab_6.h"

string PrepareForDisplay(int values[], int size, char separator) {
  // Declare our output string
  string output = "";
  // Make sure our size value is sane
  int absize = abs(size);

  // Loop through each number in the array and convert it to a char
  // Then append it to the output string
  for (int index = 0; index < absize; index++) {
    // Convert the value to a string before attempting to concatinate it
    // to_string requires C++11 however
    output += std::to_string(values[index]);
    output += separator;
  }

  // Remove the last character since the above loop will always gaurantee the
  // last character will be a seperator
  output.pop_back();

  return output;
}

bool HasValue(int values[], int size, int value) {
  bool contains_value = false;
  // Make sure our size value is sane
  int absize = abs(size);

  // Make the for behave a little bit like a while loop
  // and stop when we find the desired value
  for (int index = 0; !contains_value && (index < absize); index++) {
    // Parenthesis to make sure the compiler doesn't accidentally coerce
    // and assign values[index] to contains_value then compare it with value
    contains_value = (values[index] == value);
  }

  return contains_value;
}

int ValueAt(int values[], int size, int index, bool &error)
{
  // Make sure our size value is sane
  int absize = abs(size);

  // Set error flag before attempting anything else
  error = ((index < 0) || (index >= absize));

  // If error return zero otherwise value at index
  return (error? 0 : values[index]);
}

int Sum(int values[], int size) {
  // Make sure our size value is sane
  int result = 0, absize = abs(size);

  // Run through the list and add up all the values
  for (int index = 0; index < absize; index++) {
    result += values[index];
  }

  return result;
}

bool SwapValues(int values[], int size, int index1, int index2) {
  // Make sure our size value is sane
  int absize = abs(size);

  // Check and set the error flag before we continue
  bool error = ((index1 < 0) || (index1 >= absize)) ||
               ((index2 < 0) || (index2 >= absize));

  // If no error then proceed with the swap
  if (!error) {
    int temp = values[index1];
    values[index1] = values[index2];
    values[index2] = temp;
  }

  return !error;
}
