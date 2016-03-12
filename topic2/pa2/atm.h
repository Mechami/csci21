#ifndef ATM_H
#define ATM_H
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "savingsaccount.h"
#include "checkingaccount.h"
#include "creditaccount.h"
using namespace std;

// ATM function
void ATM();

// Account operation functions
void CreateAccount(vector<Account*>& accounts);
void MakeDeposit(vector<Account*>& accounts);
void MakeWithdrawal(vector<Account*>& accounts);
void Quit(vector<Account*>& accounts);

// Utility functions
unsigned ReadInt(string prompt_string, unsigned start, unsigned end);
void BuildAccountList(vector<Account*>& accounts, stringstream& prompt_stream);

#endif
