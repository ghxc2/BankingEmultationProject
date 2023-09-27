#include "Bank.h"
#include <fstream>
#include <iostream>
void Bank::addAcct(Account &acct) {
    allAccounts.push_back(acct);
}

Account Bank::findAcct(std::string ID, std::string PIN) {
    for (Account account : allAccounts){
        if (account.getAccountID() == ID && account.getAccountPin() == PIN){
            return account;
        }
    }
    Account newAccount;
    return newAccount;
}

void Bank::loadAccounts(std::ifstream &inf) {
    string line;
    int counter = 0;
    while (!inf.eof()){
        string ID, PIN;
        double balance;
        inf >> ID;
        inf >> PIN;
        inf >> balance;
        Account account(ID, PIN, balance);
        if (!ID.empty()){
//            cout << "ID: " << ID << " PIN: " << PIN << " BALANCE: " << balance << endl;
            addAcct(account);
            counter++;
        }
    }
    cout << counter << " Accounts loaded." << endl;
}
