#include "atm.h"

// The ATM driver function
void ATM() {
  // Build a vector for holding created accounts
  vector<Account*> accounts;
  // Build an array-map of integers-to-functions
  void (*operations[4])(vector<Account*>&) = {
    CreateAccount,
    MakeDeposit,
    MakeWithdrawal,
    Quit
  };

  unsigned choice = 0;
  // Build our user prompt once so it doesn't get concated several times during
  // the sanitize loop
  stringstream prompt;
  prompt << "What would you like to do?" << endl
         << "[1] Open an account" << endl
         << "[2] Make deposit" << endl
         << "[3] Make withdrawal" << endl
         << "[4] Quit" << endl
         << "Choice: " << flush;

  // This loop forces the user to enter a valid choice before moving on
  do {
    // Now we just pass the prompt string instead of the prompt stream
    choice = ReadInt(prompt.str(), 1, 4);
    // Subtract 1 to put the choice in range of the array
    // then call the appropriate function
    operations[choice - 1](accounts);
  } while (choice < 4);

  // Since 4 is the quit function all the cleanup is taken care of there
  // and we don't need to do anything else after the loop ends
}

void CreateAccount(vector<Account*>& accounts) {
  // Same deal is in ATM()
  // Construct the prompt then pass it to the ReadInt function
  unsigned choice = 0;
  stringstream prompt;
  prompt << "Please select account type: " << endl
         << "[1] Savings" << endl
         << "[2] Checking" << endl
         << "[3] Credit" << endl
         << "Choice: " << flush;

  do {
    choice = ReadInt(prompt.str(), 1, 3);
  } while (choice > 3);

  // Get the owner name of the new account from the user
  string owner_name = "";
  cout << "Please specify the holder name: " << flush;
  cin >> owner_name;

  // Since ReadInt is going to force the user to insert an integer from 1-3
  // We can just assume anything that is not 1 or 2 is 3
  // Allowing us to get away with a generic default case here
  switch (choice) {
    // For each case in the switch just create a new account
    // And push it into the account vector
    // Quit() will go through each entry and delete them
    // So we don't get any memory leaks
    case 1: {
      accounts.push_back(new SavingsAccount(accounts.size(), owner_name));
      break;
    }
    case 2: {
      accounts.push_back(new CheckingAccount(accounts.size(), owner_name));
      break;
    }
    default: {
      accounts.push_back(new CreditAccount(accounts.size(), owner_name));
      break;
    }
  }
}

void MakeDeposit(vector<Account*>& accounts) {
  stringstream prompt;

  // Don't do anything if we don't have any accounts to work on
  if (accounts.size() > 0) {
    prompt << "Please select account: " << endl;

    // Pass our account list and prompt stream off to the list builder
    BuildAccountList(accounts, prompt);

    prompt << "Choice: " << flush;
    // Make sure the upper bound is 1 less than the vector size
    // Otherwise we'll get a segmentation fault
    unsigned choice = ReadInt(prompt.str(), 0, accounts.size() - 1);
    // Now get the amount the user wants to deposit
    unsigned amount = ReadInt("Deposit amount: ", 0, UINT_MAX);
    // Dereference the account pointer and make the deposit
    accounts[choice]->Deposit(amount);
    // Show the user the account info along with its new balance
    cout << accounts[choice]->ToString() << endl;
  }
  else {
    cout << "An account is needed before a deposit can be made." << endl;
  }
}

void MakeWithdrawal(vector<Account*>& accounts) {
  stringstream prompt;

  // Same deal as before; Don't do anything if we don't have accounts to work on
  if (accounts.size() > 0) {
    prompt << "Please select account: " << endl;

    // Pass our account list and prompt stream off to the list builder
    BuildAccountList(accounts, prompt);

    prompt << "Choice: " << flush;
    // Likewise get the choice from the user
    unsigned choice = ReadInt(prompt.str(), 0, accounts.size() - 1);
    // Then get the withdrawal amount
    unsigned amount = ReadInt("Withdrawal amount: ", 0, UINT_MAX);
    // Then do a pointer lookup and pass the amount to the Withdraw function
    accounts[choice]->Withdraw(amount);
    // Then print out the account info with the new balance
    cout << accounts[choice]->ToString() << endl;
  }
  else {
    cout << "An account is needed before a withdrawal can be made." << endl;
  }
}

void Quit(vector<Account*>& accounts) {
  // Loop through each account in the vector
  for (unsigned index = 0; index < accounts.size(); index++) {
    // Then print out its info
    cout << accounts[index]->ToString() << endl;
    // Then delete it so we don't get memory leaks
    delete accounts[index];
  }
}

unsigned ReadInt(string prompt_string, unsigned start, unsigned end) {
  string temp_string = "";
  unsigned choice = 0;

  do {
    // Give the user their prompt
    cout << prompt_string << flush;
    // Get the character string from the user
    cin >> temp_string;
    // Stringstream will handle the actual string -> int conversion
    stringstream(temp_string) >> choice;
  // Then just check to make sure it's in the range
  // of what we're allowed to get from the user
  } while ((choice < start) || (choice > end));

  // If all goes well we send back an actual int
  return choice;
}

void BuildAccountList(vector<Account*>& accounts, stringstream& prompt_stream) {
  // Since we're working with a vector we have the potential
  // for a dynamically resizing list
  // So we use this loop to build it
  for (size_t index = 0; index < accounts.size(); index++) {
    // Since we're using the account 3 times in this loop we'll cache it here
    // That way we're not doing an indiec
    const Account* const account = accounts[index];
    prompt_stream << "[" << index << "] " << account->Owner() << " "
           << account->Id() << ": " << account->Balance() << endl;
  }
}
