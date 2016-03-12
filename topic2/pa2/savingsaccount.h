#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "account.h"
#include "checkingaccount.h"
#include "creditaccount.h"

class CheckingAccount;
class CreditAccount;

class SavingsAccount : public Account {
  public:
    SavingsAccount(unsigned long account_id, const string& owner_name);

    /**
     * @brief ToCheckingAccount
     * Converts this savings account into a checking account
     *
     * @return CheckingAccount - A CheckingAccount representation of this SavingsAccount
     */
    CheckingAccount ToCheckingAccount() const;

    /**
     * @brief ToCreditAccount
     * Converts this savings account into a credit account
     *
     * @return CreditAccount - A CreditAccount representation of this SavingsAccount
     */
    CreditAccount ToCreditAccount() const;

    /**
     * @brief TransferToChecking
     * Transfers the specified amount from this savings account
     * into the specified checking account
     */
    unsigned TransferToChecking(CheckingAccount& account, unsigned amount);

    /**
     * @brief TransferToCredit
     * Transfers the specified amount from this savings account
     * into the specified credit account
     */
    unsigned TransferToCredit(CreditAccount& account, unsigned amount);

    /**
     * @brief ToString
     * Returns a string representing this savings account
     * @return string - A string representing this savings account
     * in the form of: "holder_name_ [Savings account_id_]: balance_"
     */
    string ToString() const;
  private:
};

#endif
