#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "account.h"
#include "savingsaccount.h"
#include "creditaccount.h"

class SavingsAccount;
class CreditAccount;

class CheckingAccount : public Account {
  public:
    CheckingAccount(unsigned long account_id, const string& owner_name);

    /**
     * @brief ToSavingsAccount
     * Converts this checking account into a savings account
     *
     * @return SavingsAccount - A SavingsAccount representation of this CheckingAccount
     */
    SavingsAccount ToSavingsAccount() const;

    /**
     * @brief ToCreditAccount
     * Converts this checking account into a credit account
     *
     * @return CreditAccount - A CreditAccount representation of this CheckingAccount
     */
    CreditAccount ToCreditAccount() const;

    /**
     * @brief TransferToSavings
     * Transfers the specified amount from this checking account
     * into the specified savings account
     */
    unsigned TransferToSavings(SavingsAccount& account, unsigned amount);

    /**
     * @brief TransferToCredit
     * Transfers the specified amount from this checking account
     * into the specified credit account
     */
    unsigned TransferToCredit(CreditAccount& account, unsigned amount);

    /**
     * @brief ToString
     * Returns a string representing this credit account
     * @return string - A string representing this credit account
     * in the form of: "holder_name_ [Checking account_id_]: balance_"
     */
    string ToString() const;
  private:
};

#endif
