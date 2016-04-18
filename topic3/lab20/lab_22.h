/*
 * Name        : lab_22.h
 * Author      : Luke Sathrum
 * Description : Header File for Lab #22. DO NOT ALTER!
 */

#ifndef LAB_H
#define LAB_H

#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;


/*
 * Compute and return the factorial of a value, using a recursive algorithm. Zero factorial
 * will return 1.
 * @param value an unsigned integer containing the value for which the factorial will be computed
 * @return an unsigned integer containing the computed factorial of the value
 */
unsigned int Factorial(unsigned int value);

/*
 * Return a specified value in a Fibonacci sequence. The lowest value requested in the sequence
 * must never be less than one.
 * @param fibValue an unsigned integer specifying which value in the Fibonacci sequence to return
 * @return an unsigned integer containing the requested value in the Fibonacci sequence
 */
unsigned int Fibonacci(unsigned int fib_value);

/*
 * Test a single word to see if it is a palindrome. The word must be all in the same case
 * (upper or lower) and cannot contain spaces, digits, or punctuation.
 * @param word a string containing the word to be tested
 * @return true of word is a palindrome, else false; empty string and single character strings
 *         are considered palindromes
 */
bool WordIsPalindrome(string word);

/*
 * Produce a string containing the contents of an array, separated by single spaces,
 * starting at a specified index and going forward to the end of the array. The returned
 * string will contain an extra space character after the last value added.
 * @param array an integer array containing the values to be added to the string
 * @param start an unsigned integer containing the index of the first value in the array to be added
 *        to the output string
 * @param size an unsigned integer containing the number of elements in the array
 * @return a string containing the contents of the array, separated by spaces; returns empty string
 *         if the startIndex is >= the size of the array
 */
string ArrayForwardsAsString(int array[], unsigned int start,
                             unsigned int size);

/*
 * Produce a string containing the contents of an array, separated by single spaces,
 * starting at a specified index and going backward to the beginning of the array. The returned
 * string will contain an extra space character after the last value added.
 * @param array an integer array containing the values to be added to the string
 * @param start an integer containing the index of the first value in the array to be added
 *        to the output string
 * @param size an unsigned integer containing the number of elements in the array
 * @return a string containing the contents of the array, separated by spaces, in reverse order; returns empty string
 *         if the startIndex is < zero
 */
string ArrayBackwardsAsString(int array[], int start, unsigned int size);

#endif
