/*
 * Name        : lab_7.cpp
 * Author      : Philip Muzzall
 * Description : Working with File I/O
 * Sources     : cppreference.com, cplusplus.com
 */

#include "lab_7.h"

// Declare our includes and namespaces here since we aren't
// allowed to modify the header file
#include <functional>
using std::function;

// Map each function to the string that is supposed to represent it
const map<string, function<void()>  > function_map {
  { "10", OnTen },
  { "20", OnTwenty },
  { "30", OnThirty },
  { "40", OnForty },
  { "50", OnFifty },
};

bool ProcessFile(string filename)
{
  // Make sure we actually have a filename before attempting to open said file
  bool error = filename.empty();
  ifstream fin;

  // If we have a valid descriptor then open the file
  if (!error) {
    fin.open(filename);
  }

  // Declare and initialize our string here so
  // it doesn't get destroyed and rebuilt each iteration
  string current_line = "";
  fin >> current_line;

  while (fin.is_open() && fin.good()) {
    // Count will return 1 or 0 depending on whether or not a key has been
    // associated with a handler function in the map. If it has we call it
    // otherwise we call the error handler.
    function_map.count(current_line)? function_map.at(current_line)() : OnError();

    // Advance to the next line
    fin >> current_line;
  }

  // If the file was opened then close it
  if (fin.is_open()) {
    fin.close();
  }

  return error;
}

void ProcessArguments(int argc, char* argv[]) {
  // Create a C-String representing the current argument here
  const char* arg = "";

  for (int index = 1; index < argc; index += 1) {
    // Get the current argument from the array
    arg = argv[index];

    // Call the appropriate handler if the argument has one associated
    // Otherwise call the error handler
    function_map.count(arg)? function_map.at(arg)() : OnError();
  }
}
