#include <string>
#include "Account.h"
#include "Bank.h"
#pragma once
class ATM{
private:
    Bank bank;
public:
    ATM();
    ATM(Bank bk);
    int start();
    void transactions(Account& acct);

};