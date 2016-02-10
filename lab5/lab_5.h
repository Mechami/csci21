/*
 * Name        : lab_5.h
 * Author      : Philip Muzzall
 * Description : Practicing Functions. Use this file to write your
 *               Function Prototypes (what goes above main()).
 */

#ifndef LAB_H
#define LAB_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <streambuf>
using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
 * Create defines for pure functions.
 * If we are using a GNU C/C++ compiler then define the attributes
 * Otherwise define them as self-enclosed comments so other compilers don't bork
 * But also make sure we are using a version of GNU C/C++ that supports them.
 * GCC 3.1.x was the earliest version I could find in the manual that supports
 * these attributes.
 */
#if defined(__GNUC__) && (__GNUC__ > 3) && (__GNUC_MINOR__ > 1)
  #define constpure __attribute__((const))
  #define pure __attribute__((pure))
#else
  #define constpure /**/
  #define pure /**/
#endif

/*
 * Function Name: Hello
 *
 * Displays "Hello world!" to stdout (cout) (no newline character after)
 */
void Hello();

/*
 * Function Name: PrintMessage
 *
 * Displays the string parameter to stdout (no newline character)
 * @param const string& - The string to display to stdout
 */
void PrintMessage(const string& message);

/*
 * Function Name: GetAnswer
 *
 * Returns the integer value 42.
 * @return int - The value 42
 */
int GetAnswer() constpure;

/*
 * Function Name: FindLarger
 *
 * Returns the larger of the two parameter values. Should work correctly
 * if the values are equivalent (returns either one)
 * @param int - The first value
 * @param int - The second value
 * @return int - The larger of the two values, or either one if they are equal
 */
int FindLarger(int x, int y) constpure;

/*
 * Function Name: BuildMessage
 *
 * Return the string "Message: STRING", where STRING is replaced by the value of
 * the first parameter (string). If second parameter (bool) is true, convert
 * first parameter (string) to all uppercase letters before concatenating it
 * with "Message: ". If first parameter is the empty string, return
 * "Message: empty".
 * @param string - A message.
 *               - Defaults to "" (empty string)
 * @param bool - To indicate if we should uppercase letters or not
 *             - Defaults to false
 */
string BuildMessage(string message = "", bool uppercase_all = false) constpure;

/*
 * Function Name: UppercaseString
 *
 * Takes a string reference and uppercases every character within it
 * @param string& - The string to uppercase.
 */
void UppercaseString(string& message);

#endif
