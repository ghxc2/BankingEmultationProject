#include <iostream>
#include "Account.h"

Account::Account() {
    setAccountBalance(0.0);
}

Account::Account(std::string accountID, std::string accountPIN, double accountBalance) {
    setAccountBalance(accountBalance);
    setAccountID(accountID);
    setAccountPin(accountPIN);
}

double Account::getAccountBalance() {
    return accountBalance;
}

string Account::getAccountID() {
    return accountID;
}

string Account::getAccountPin() {
    return accountPIN;
}

void Account::setAccountBalance(double balance) {
    accountBalance = balance;
}

void Account::setAccountID(std::string ID) {
    accountID = ID;
}

void Account::setAccountPin(std::string PIN) {
    accountPIN = PIN;
}

void Account::Balance() {
    cout << "Balance: $" <<  getAccountBalance() << endl;
}

void Account::deposit(double amount) {
    double balance = getAccountBalance();
    if (amount >= 0.0){
        setAccountBalance(balance + amount);
    }
}

void Account::withdraw(double amount) {
    double balance = getAccountBalance();
    if (amount > 0.0 && amount < balance){
        setAccountBalance(balance - amount);
    }
}