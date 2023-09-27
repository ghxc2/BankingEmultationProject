#include <string>
#pragma once
using namespace std;
class Account{
private:
   string accountID, accountPIN;
   double accountBalance;
public:
    Account();
    Account(string accountID, string accountPIN, double accountBalance);
   string getAccountID();
   void setAccountID(string ID);
   string getAccountPin();
   void setAccountPin(string PIN);
   double getAccountBalance();
   void setAccountBalance(double Balance);
   void Balance();
   void deposit(double amount);
   void withdraw(double amount);
};