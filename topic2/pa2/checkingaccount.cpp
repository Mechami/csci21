#include "checkingaccount.h"

CheckingAccount::CheckingAccount(unsigned long account_id,
                               const string& owner_name)
               : Account::Account(account_id, owner_name) {
}

SavingsAccount CheckingAccount::ToSavingsAccount() const {
  SavingsAccount savings_account(account_id_, holder_name_);

  bool deposited = false;
  long counter = 0;

  /*
  * A bit of a dumb hack but this way we don't need
  * To mess with friending in order to access the
  * balance_ variable for checking_account
  */
  do {
    /*
    * Since Deposit returns the amount deposited
    * and we are only depositing one at a time
    * we are effectively getting a boolean back
    * stating whether or not we can deposit anymore in the
    * new checking account
    */
    deposited = savings_account.Deposit(1);
    counter++;
  } while (deposited && (counter < balance_));

  return savings_account;
}

CreditAccount CheckingAccount::ToCreditAccount() const {
  CreditAccount credit_account(account_id_, holder_name_);

  for (long counter = 0; counter <= balance_; counter++) {
    credit_account.Deposit(1);
  }

  return credit_account;
}

unsigned CheckingAccount::TransferToSavings(SavingsAccount& account,
                                            unsigned amount) {
  bool deposited = false;
  unsigned counter = 0;

  do {
    deposited = account.Deposit(1);
    counter++;
  } while (deposited && (counter < amount) && (balance_ > 0));

  return counter;
}

unsigned CheckingAccount::TransferToCredit(CreditAccount& account,
                                            unsigned amount) {
  bool deposited = false;
  unsigned counter = 0;

  do {
    deposited = account.Deposit(1);
    counter++;
  } while (deposited && (counter < amount) && (balance_ > 0));

  return counter;
}

string CheckingAccount::ToString() const {
  stringstream ss;

  ss << holder_name_ << " [Checking " << account_id_ << "]: " << balance_;

  return ss.str();
}
