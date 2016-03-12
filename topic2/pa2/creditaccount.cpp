#include "creditaccount.h"

CreditAccount::CreditAccount(unsigned long account_id,
                             const string& owner_name)
              : Account::Account(account_id, owner_name) {
}

SavingsAccount CreditAccount::ToSavingsAccount() const {
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

CheckingAccount CreditAccount::ToCheckingAccount() const {
  CheckingAccount checking_account(account_id_, holder_name_);

  bool deposited = false;
  long counter = 0;

  do {
    deposited = checking_account.Deposit(1);
    counter++;
  } while (deposited && (counter < balance_));

  return checking_account;
}

unsigned CreditAccount::TransferToSavings(SavingsAccount& account,
                                            unsigned amount) {
  bool deposited = false;
  unsigned counter = 0;

  do {
    deposited = account.Deposit(1);
    counter++;
  } while (deposited && (counter < amount) && (balance_ > 0));

  return counter;
}

unsigned CreditAccount::TransferToChecking(CheckingAccount& account,
                                            unsigned amount) {
  bool deposited = false;
  unsigned counter = 0;

  do {
    deposited = account.Deposit(1);
    counter++;
  } while (deposited && (counter < amount) && (balance_ > 0));

  return counter;
}

string CreditAccount::ToString() const {
  stringstream ss;

  ss << holder_name_ << " [Credit " << account_id_ << "]: " << balance_;

  return ss.str();
}
