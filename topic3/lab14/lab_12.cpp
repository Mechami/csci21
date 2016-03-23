/*
 * Name        : lab_12.cpp
 * Author      : Philip Muzzall
 * Description : Working with Pointers and Dynamic Variables / Arrays
 */
#include "lab_12.h"

// Not supposed to modify header so include this here
#include <algorithm>
using std::max;
using std::min;

int* MakeDynoIntArray(unsigned int size) {
  return new int[size];
}

int Sum(int* the_array, unsigned int array_size)  {
    int total = 0;

    // Throw if pointer is null
    if (!the_array) {
        throw "NULL ARRAY REFERENCE";
    }

    // Otherwise compute sum
    for (unsigned index = 0; index < array_size; index++) {
        total += the_array[index];
    }

    return total;
}

int Max(int* the_array, unsigned int array_size) {
    // Set the initial value to the lowest possible
    // To do that we just set the sign bit as that results
    // in the lowest negative value that ints can hold
    // We do that by subtracting 1 from the computed bitsize
    // so we don't push the 1 bit into the 33rd bit position
    int largest = 1 << ((sizeof(int) * 8) - 1);

    // Throw if pointer is null
    if (!the_array) {
        throw "NULL ARRAY REFERENCE";
    }

    // Otherwise compute largest value
    for (unsigned index = 0; index < array_size; index++) {
        largest = max(the_array[index], largest);
    }

    return largest;
}

int Min(int* the_array, unsigned int array_size) {
    // Here we want the highest value possible
    // But setting the sign bit results in a negative
    // So we subtract 2 instead of 1 to get the bit just before the sign bit
    int smallest = 1 << ((sizeof(int) * 8) - 2);

    // Throw if pointer is null
    if (!the_array) {
        throw "NULL ARRAY REFERENCE";
    }

    // Otherwise compute smallest value
    for (unsigned index = 0; index < array_size; index++) {
        smallest = min(the_array[index], smallest);
    }

    return smallest;
}
