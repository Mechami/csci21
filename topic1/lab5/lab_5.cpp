/*
 * Name        : lab_5.cpp
 * Author      : Philip Muzzall
 * Description : Practicing Functions. Use this file to write your
 *               Function Definitions (what goes below main()).
 */

#include "lab_5.h"

/*
 * The Hello function is not pure since it produces an I/O write to stdout.
 * Though one could say that it is pure since its sole purpose is to write a
 * literal string value to stdout.
 */
void Hello()
{
  cout << "Hello world!" << std::flush;
}

/*
 * Like the Hello function PrintMessage is not considered pure because it
 * performs an I/O write to stdout.
 * However like Hello it could be considered pure since its sole purpose is to
 * write to stdout in addition to the fact that what it writes is dependant
 * entirely on the contents of its string parameter.
 */
void PrintMessage(const string& message)
{
  cout << message << std::flush;
}

/*
 * GetAnswer is considered pure because it returns
 * absolutely nothing but a hard-coded literal representing the value of 42.
 */
int GetAnswer()
{
  return 42;
}

/*
 * FindLarger is considered pure because the value it returns is dependant
 * entirely on the two parameters it is passed; If they are equivalent or
 * x is greater than y then x is guaranteed to be returned.
 */
int FindLarger(int x, int y)
{
  return ((x >= y)? x : y);
}

/*
 * BuildMessage takes its two parameters by value and not reference
 * This means that all the data required is pushed onto the stack when
 * BuildMessage's stackframe is built. The result is that all the data
 * that BuildMessage requires is local to its stackframe and does not reside on
 * the heap which makes the output of BuildMessage entirely dependant on
 * the contents of its parameters; This in turn makes BuildMessage pure.
 */
string BuildMessage(string message, bool uppercase_all)
{
  bool not_empty = message.length() > 0;

  if (not_empty && uppercase_all)
  {
    UppercaseString(message);
  }

  return ("Message: " + (not_empty? message : "empty"));
}

/*
 * Unlike BuildMessage UppercaseString does not actually return something;
 * It modifies an object stored in stack memory outside its scope.
 * This makes it impure.
 */
void UppercaseString(string& message)
{
  for (unsigned i = 0; i < message.length(); i++)
  {
    message[i] = toupper(message[i]);
  }
}
