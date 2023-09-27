#include <string>
#include <vector>
#include "Account.h"
#pragma once
using namespace std;
class Bank{
private:
    vector<Account> allAccounts;
public:
    Account findAcct(string ID, string PIN);
    void addAcct(Account& acct);
    void loadAccounts(ifstream& inf);
};