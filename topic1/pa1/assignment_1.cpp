/*
 * Name        : Programming Assignment 1
 * Author      : Philip Muzzall
 * Description : Collection of programs for Topic 1 review
 * Sources     : cplusplus.com, cppreference.com
 */

#include "assignment_1.h"

bool CheckAlphabetic(const string& input_string) {
  // Assume the string is fully alphabetic until proven false or empty
  bool is_alpha = !input_string.empty();
  // Cache the string length so we only make one function call
  unsigned string_length = input_string.length();

  // Keep iterating for as long as we are alphabetic and have a valid index
  for (unsigned index = 0; is_alpha && (index < string_length); index += 1) {
    // Determine if the current string index is alphabetic
    is_alpha = static_cast<bool>(isalpha(input_string[index]));
  }

  return is_alpha;
}

int CountWords(string input_string) {
  // Determine whether or not we have at least 1 word
  int word_count = (!input_string.empty() && (input_string != " "));
  // Cache the string length here
  unsigned string_length = input_string.length();

  // Loop through each character and increment the word_count by 1 for each
  // space character found
  for (unsigned index = 0; index < string_length; index += 1) {
    (input_string[index] == 0x20)? (word_count += 1) : 0;
  }

  return word_count;
}

bool EncryptString(string& input_string, int shift_count) {
  // Cache the alphabetic flag
  bool is_alphabetic = CheckAlphabetic(input_string);

  // Run the loop if we are alphabetic otherwise skip
  for (unsigned index = 0; is_alphabetic && (index < input_string.length()); index++) {
    char index_char = input_string[index];
    // ShiftCar does the actual encoding per-character
    input_string[index] = ShiftCar(index_char, shift_count, isupper(index_char));
  }

  return is_alphabetic;
}

bool DecryptString(string& input_string, int shift_count) {
  bool is_alphabetic = CheckAlphabetic(input_string);

  for (unsigned index = 0; is_alphabetic && (index < input_string.length()); index++) {
    char index_char = input_string[index];
    // Exactly the same as EncryptString() except we pass a negative shift_count
    // to decrypt the string
    input_string[index] = ShiftCar(index_char, -shift_count, isupper(index_char));
  }

  return is_alphabetic;
}

double ComputeAverage(double double_array[], unsigned size) {
  double average = 0.0;

  // Compute the sum of the array
  for (unsigned index = 0; index < size; index += 1) {
    average += double_array[index];
  }

  // Then divide by size to get the average
  average /= static_cast<double>(size);

  return average;
}

// Loop through each double and make it the new minimum if it was smaller than
// the previous minimum value
double FindMinValue(double double_array[], unsigned size) {
  double minimum = 0.0;

  for (unsigned index = 0; index < size; index += 1) {
    // Set the new minimum to the current index if it is smaller to the
    // current minimum otherwise do nothing (0 is there to shut the compiler up)
    (double_array[index] < minimum)? (minimum = double_array[index]) : 0;
  }

  return minimum;
}

double FindMaxValue(double double_array[], unsigned size) {
  double maximum = 0.0;

  for (unsigned index = 0; index < size; index += 1) {
    // Same algorithm as before but the comparison signs are switched
    (double_array[index] > maximum)? (maximum = double_array[index]) : 0;
  }

  return maximum;
}

char ShiftCar(char old_char, int shift_amount, bool uppercase) {
  int int_char = static_cast<int>(old_char);
  int start = uppercase? 0x41 : 0x61;
  int end = uppercase? 0x5A : 0x7A;

  // Shift to the right if shift_amount is positive
  while (shift_amount > 0) {
    // Use sequence point operator to set char value -then- adjust shift amount
    (int_char < end)? 0 : (int_char = start, shift_amount -= 1);
    int_char += 1;
    shift_amount -= 1;
  }

  // Otherwise shift to the left if shift_amount is negative
  while (shift_amount < 0) {
    // Use sequence point operator to set char value -then- adjust shift amount
    (int_char > start)? 0 : (int_char = end, shift_amount += 1);
    int_char -= 1;
    shift_amount += 1;
  }

  return static_cast<char>(int_char);
}
