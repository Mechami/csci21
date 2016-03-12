#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <sstream>
#include <climits>
using std::string;
using std::stringstream;

/**
 * Account
 * Generic bank account class
 */
class Account {
  public:
    /**
     * @brief Id
     * Returns the ID number of this account
     *
     * @return unsigned long long - The ID of this account
     */
    unsigned long Id() const;

    /**
     * @brief Owner
     * Returns a constant string reference of the account holder's name
     *
     * @return const string& - The name of the account holder in string format
     */
    const string& Owner() const;

    /**
     * @brief Owner
     * Sets the new owner of this account to the passed owner string
     *
     * @param const string& new_owner - A string representing the new owner
     * of this account
     */
    void Owner(const string& new_owner);

    /**
     * @brief Balance
     * Returns the balance of this account in USD
     */
    long Balance() const;

    /**
     * @brief Deposit
     * Deposits USD into this account
     * @param unsigned - Amount to deposit
     * @return unsigned - The amount actually deposited
     */
    unsigned Deposit(unsigned amount);

    /**
     * @brief Withdraw
     * Withdraws USD from this account
     * @param unsigned - Amount to withdraw
     * @return unsigned - The amount actually withdrawn
     */
    unsigned Withdraw(unsigned amount);

    /**
     * @brief Wire
     * Wires money from this account to another
     */
    void Wire(Account& other_account, unsigned wire_amount);

    /**
     * @brief ToString
     * Returns a string representing this account
     * @return string - A string representing this account
     * in the form of: "holder_name_ [Generic account_id_]: balance_"
     */
    virtual string ToString() const;

    virtual ~Account();
  protected:
    Account(unsigned long account_id, const string& owner_name);

    const unsigned long account_id_;
    string holder_name_;
    long balance_;
};

#endif
