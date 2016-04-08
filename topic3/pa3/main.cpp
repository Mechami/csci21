#include <iostream>
#include <string>
#include <sstream>
#include "prize.h"
#include "box.h"
using namespace std;

unsigned displayMenu();
void prizeOperation(Prize& prize);
void boxOperation(Box& box);

int main() {
  Prize prize;
  Box box;
  unsigned choice = 0;

  do {
    choice = displayMenu();
    if (choice == 1) {
      prizeOperation(prize);
    }
    else if (choice == 2) {
      boxOperation(box);
    }
  } while (choice != 3);

  return 0;
}

unsigned displayMenu() {
  string input = "";
  unsigned choice = 0;

  cout << "Please select an option:" << endl
       << "[1] Use Prize functions" << endl
       << "[2] Use Box functions" << endl
       << "[3] Quit" << endl
       << "Choice: " << flush;
  cin >> input;
  cout << endl;
  stringstream(input) >> choice;

  return choice;
}

void prizeOperation(Prize& prize) {
  string input = "";
  unsigned choice = 0;

  cout << "Please pick an operation: " << endl
       << "[1] Get prize name" << endl
       << "[2] Set prize name" << endl
       << "[3] Get prize value" << endl
       << "[4] Set prize value" << endl
       << "Choice: " << flush;
  cin >> input;
  cout << endl;
  stringstream(input) >> choice;

  switch(choice) {
    case 1: {
      cout << "Prize name is: " << prize.getPrizeName() << endl;
      break;
    }
    case 2: {
      cout << "Please enter new prize name: " << flush;
      string prize_name = "";
      cin >> prize_name;
      prize.setPrizeName(prize_name);
      cout << endl << "Prize name is now: " << prize.getPrizeName() << endl;
      break;
    }
    case 3: {
      cout << "Prize value is: " << prize.getPrizeValue() << endl;
      break;
    }
    case 4: {
      cout << "Please enter new prize value: " << flush;
      string prize_value = "";
      cin >> prize_value;
      int value = 0;
      stringstream(prize_value) >> value;
      prize.setPrizeValue(value);
      cout << "Prize value is now: " << prize.getPrizeValue() << endl;
      break;
    }
    default: {
      cout << "Invalid option" << endl;
      break;
    }
  }
}

void boxOperation(Box &box) {
  string input = "";
  unsigned choice = 0;

  cout << "Please pick an operation: " << endl
       << "[1] Get box number" << endl
       << "[2] Set box number" << endl
       << "[3] Get box color" << endl
       << "[4] Set box color" << endl
       << "[5] Get prize capacity" << endl
       << "[6] Get prize count" << endl
       << "[7] Add prize" << endl
       << "[8] Get prize" << endl
       << "[9] Remove prize" << endl
       << "Choice: " << flush;
  cin >> input;
  cout << endl;
  stringstream(input) >> choice;

  switch(choice) {
    case 1: {
      cout << "Box number is: " << box.getBoxNumber() << endl;
      break;
    }
    case 2: {
      cout << "Please enter new box number: " << flush;
      string box_number = "";
      cin >> box_number;
      int number = 0;
      stringstream(box_number) >> number;
      box.setBoxNumber(number);
      cout << "Box number is now: " << box.getBoxNumber() << endl;
      break;
    }
    case 3: {
      cout << "Box color is: " << box.getBoxColor() << endl;
      break;
    }
    case 4: {
      string color = "";
      cout << "Please enter a color: " << flush;
      cin >> color;
      box.setBoxColor(color);
      cout << "Box color is now: " << box.getBoxColor() << endl;
      break;
    }
    case 5: {
      cout << "Prize capacity is: " << box.getPrizeCapacity() << endl;
      break;
    }
    case 6: {
      cout << "Prize count is: " << box.getPrizeCount() << endl;
      break;
    }
    case 7: {
      string name = "";
      string value = "";
      cout << "Please enter a name and value for the prize" << endl
           << "Name: " << flush;
      cin >> name;
      cout << "Value: " << flush;
      cin >> value;
      int prize_value = 0;
      stringstream(value) >> prize_value;
      cout << "The prize was added " << (box.addPrize(Prize(name, prize_value))?
                                         "successfully" :
                                         "unsuccessfully") << endl;
      break;
    }
    case 8: {
      string index_string = "";
      cout << "Please choose an index equal to or greater than zero: " << flush;
      cin >> index_string;
      unsigned index = 0;
      stringstream(index_string) >> index;
      Prize prize = box.getPrize(index);
      cout << "Prize at index " << index << " is:" << endl
           << "Name: " << prize.getPrizeName() << endl
           << "Value: " << prize.getPrizeValue() << endl;
      break;
    }
    case 9: {
      string index_string = "";
      cout << "Select an index equal to or greater than zero to remove: " << flush;
      cin >> index_string;
      unsigned index = 0;
      stringstream(index_string) >> index;
      Prize prize = box.removePrize(index);
      cout << "The prize removed from index " << index << " was: " << endl
           << "Name: " << prize.getPrizeName() << endl
           << "Value: " << prize.getPrizeValue() << endl;
      break;
    }
    default: {
      cout << "Invalid choice" << endl;
      break;
    }
  }
}
