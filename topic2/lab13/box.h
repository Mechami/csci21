#ifndef BOX_H
#define BOX_H
#include <iostream>
using std::ostringstream;

/*
 * Function Name: Sum
 * Return the "sum" of the values in the array. Your initial sum 	should be set
 * to "zero" in your algorithm. To do this use T().
 * @param T values - An array of any type
 * @param unsigned int size - The size of the array
 * @return T - The sum of the values in the array
 */
template<typename T>
T Sum(T array[], unsigned int size);

/**
 * Class Name: Box
 * A generic wrapper for templated types
 */
template<typename T>
class Box {
  public:
    Box(T contents) {
      contents_ = contents;
    }

    void setContents(T new_contents) {
      contents_ = new_contents;
    }

    T getContents() const {
      return contents_;
    }

    friend ostringstream& operator<<(ostringstream& stream, Box<T> box) {
      stream << box.contents_;
      return stream;
    }

  private:
    T contents_;
};

template<typename T>
T Sum(T array[], unsigned int size) {
  T summation = T();

  for (unsigned int index = 0; index < size; index++) {
    summation += array[index];
  }

  return summation;
}

#endif
