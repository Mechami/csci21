/*
 * Name        : Programming Assignment 1
 * Author      : Philip Muzzall
 * Description : Collection of programs for Topic 1 review
 * Sources     : cplusplus.com, cppreference.com
 */

#ifndef ASSIGNMENT_1_H
#define ASSIGNMENT_1_H

#include <string>
using std::string;

/*
 * Determine if the passed string is fully alphabetic.
 * @param const string& input_string - The string to be checked
 * @return bool - The truth value representing whether or not the string is
 *                entirely alphabetic
 */
bool CheckAlphabetic(const string& input_string);

/*
 * Determine the number of spaces contained in thepassed string.
 * @param string input_string - The string to be counted for spaces
 * @return int - The number of spaces found within the string
 */
int CountWords(string input_string);

/*
 * Encrypts a string by performing a caesar cipher shift
 * @param string& input_string - The string to be encrypted
 * @param int shift_count - Number of characters to shift by
 * @return bool - Whether or not the string was successfully encrypted
 */
bool EncryptString(string& input_string, int shift_count);

/*
 * Decrypts a caesar cipher shift back into a human readable string
 * @param string& input_string - The string to be decrypted
 * @param int shift_count - Number of characters to shift by
 * @return bool - Whether or not the string was successfully decrypted
 */
bool DecryptString(string& input_string, int shift_count);

/*
 * Compute the mean average in an array
 * @param double[] double_array - The array to compute the mean average of
 * @param unsigned size - The size of the array
 * @return double - The mean average of the array
 */
double ComputeAverage(double double_array[], unsigned size);

/*
 * Finds and returns the minimum value in the array
 * @param double[] double_array - The array to parse
 * @param unsigned size - The size of the array
 * @return double - The smallest value in the array
 */
double FindMinValue(double double_array[], unsigned size);

/*
 * Finds and returns the maximum value in the array
 * @param double[] double_array - The array to parse
 * @param unsigned size - The size of the array
 * @return double - The largest value in the array
 */
double FindMaxValue(double double_array[], unsigned size);

/*
 * Helper function for Encrypt/DecryptString
 * Computes the shift of a character
 * @param char old_char - The char to shift
 * @param int shift_amount - The amount to shift by. Negative values shift left
 * while positive values shift right
 * @param bool uppercase - Whether or not old_char is an uppercase letter
 * @return char - The shifted char
 */
char ShiftCar(char old_char, int shift_amount, bool uppercase);

#endif /* ASSIGNMENT_1_H */
