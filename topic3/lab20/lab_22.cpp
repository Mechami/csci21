/*
 * Name        : lab_22.cpp
 * Author      : YOUR NAME
 * Description : Recursive Functions
 */

#include "lab_22.h"

unsigned int Factorial(unsigned int value) {
  unsigned result = (value < 2)? 1 : value;

  if (value > 1) {
    result *= Factorial(value - 1);
  }

  return result;
}

unsigned int Fibonacci(unsigned int fib_value) {
  unsigned result = fib_value;

  if (fib_value > 1) {
    result = Fibonacci(fib_value - 1);
    result += Fibonacci(fib_value - 2);
  }

  return result;
}

bool WordIsPalindrome(string word) {
  bool result = (word.length() < 1);

  if ((word.length() > 0) && (word[0] == word[word.length() - 1])) {
    result = WordIsPalindrome(word.substr(1, word.length() - 2));
  }

  return result;
}

string ArrayForwardsAsString(int array[], unsigned int start, unsigned int size) {
  stringstream ss;

  if (start < size) {
    ss << array[start] << ' ' << ArrayForwardsAsString(array, start + 1, size);
  }

  return ss.str();
}

string ArrayBackwardsAsString(int array[], int start, unsigned int size) {
  stringstream ss;

  if (start >= 0) {
    ss << array[start] << ' ' << ArrayBackwardsAsString(array, start - 1, size);
  }

  return ss.str();
}
