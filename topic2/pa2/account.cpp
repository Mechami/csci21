#include "account.h"

Account::Account(unsigned long account_id,
                 const string& owner_name)
        : account_id_(account_id), holder_name_(owner_name), balance_(0) {
}

unsigned long Account::Id() const {
  return account_id_;
}

const string& Account::Owner() const {
  return holder_name_;
}

void Account::Owner(const string& new_owner) {
  holder_name_ = new_owner;
}

long Account::Balance() const {
  return balance_;
}

unsigned Account::Deposit(unsigned amount) {
  unsigned deposit_amount = amount;

  for (long counter = 0; (balance_ < LONG_MAX) &&
                         (counter < amount); counter++) {
    balance_++;
    deposit_amount--;
  }

  return amount;
}

unsigned Account::Withdraw(unsigned amount) {
  unsigned withdrew = 0;

  for (long counter = 0; (balance_ > LONG_MIN) &&
                         (counter < amount); counter++) {
    balance_--;
    withdrew++;
  }

  return withdrew;
}

void Account::Wire(Account& other_account, unsigned wire_amount) {
  for (long counter = 0; (other_account.balance_ < LONG_MAX) &&
                         (this->balance_ > 0) &&
                         (counter < wire_amount); counter++) {
    other_account.balance_++;
    this->balance_--;
  }
}

string Account::ToString() const {
  stringstream ss;

  ss << holder_name_ << " [ Generic " << account_id_ << "]: " << balance_;

  return ss.str();
}

Account::~Account() {
  // Empty since none of our member variables need special destruction handling
}
