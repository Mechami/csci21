/*
 * Name        : lab_12.h
 * Author      : Luke Sathrum
 * Description : Header File for Lab #12. DO NOT ALTER!
 */

#ifndef LAB_H
#define LAB_H

#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::endl;
using std::string;

/*
 * Allocate memory for a dynamic array of integers.
 * @param unsigned int size - The desired size of the dynamic array
 * @return int* - A pointer to the newly allocated integer array
 */
int* MakeDynoIntArray(unsigned int size);

/*
 * Compute the sum of an array.
 * @param int* the_array - The array for which the sum will be computed
 * @param unsigned int array_size - The size of the_array
 * @return int - An integer containing the sum of the array
 * @throw The message "NULL ARRAY REFERENCE" if the_array is NULL
 *        Syntax: throw "The Message to throw";
 */
int Sum(int* the_array, unsigned int array_size);

/*
 * Identify the max value in an array.
 * @param int* the_array - The array for which the max value will be identified
 * @param unsigned int array_size - The size of the_array
 * @return int - An integer containing the max value of the array
 * @throw The message "NULL ARRAY REFERENCE" if the_array is NULL
 *        Syntax: throw "The Message to throw";
 */
int Max(int* the_array, unsigned int array_size);

/*
 * Identify the min value in an array.
 * @param int* the_array - The array for which the min value will be identified
 * @param unsigned int array_size - The size of the_array
 * @return int - An integer containing the min value of the array
 * @throw The message "NULL ARRAY REFERENCE" if the_array is NULL
 *        Syntax: throw "The Message to throw";
 */
int Min(int* the_array, unsigned int array_size);

#endif
