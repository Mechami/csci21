#ifndef CREDITACCOUNT_H
#define CREDITACCOUNT_H
#include "account.h"
#include "savingsaccount.h"
#include "checkingaccount.h"

class SavingsAccount;
class CheckingAccount;

class CreditAccount : public Account {
  public:
    CreditAccount(unsigned long account_id, const string& owner_name);

    /**
     * @brief ToSavingsAccount
     * Converts this credit account into a savings account
     *
     * @return SavingsAccount - A SavingsAccount representation of this CreditAccount
     */
    SavingsAccount ToSavingsAccount() const;

    /**
     * @brief ToCheckingAccount
     * Converts this credit account into a checking account
     *
     * @return CheckingAccount - A CheckingAccount representation of this CreditAccount
     */
    CheckingAccount ToCheckingAccount() const;

    /**
     * @brief TransferToSavings
     * Transfers the specified amount from this credit account
     * into the specified savings account
     */
    unsigned TransferToSavings(SavingsAccount& account, unsigned amount);

    /**
     * @brief TransferToChecking
     * Transfers the specified amount from this credit account
     * into the specified checking account
     */
    unsigned TransferToChecking(CheckingAccount& account, unsigned amount);

    /**
     * @brief ToString
     * Returns a string representing this credit account
     * @return string - A string representing this credit account
     * in the form of: "holder_name_ [Credit account_id_]: balance_"
     */
    string ToString() const;
  private:
};

#endif
