#include <iostream>
#include <fstream>
#include "ATM.h"
#include "Bank.h"
#include "Account.h"
using namespace std;
ATM::ATM() {
    Bank newBank;
    bank = newBank;
}

ATM::ATM(Bank bk) {
    bank = bk;
}

int ATM::start() {
    // Start Login Process
    cout << "Please enter your command" << endl;
    cout << "Q - quit/exit" << endl;
    cout << "L - login to account" << endl;
    string answer;
    cin >> answer;

//    cout << "Response: " << answer << endl;

    // If user chooses to login
    if (answer == "L"){
        Account account;
        // Loop until Account found
        int counter = 0;
        while (counter < 3){
            string ID, PIN;
            cout << "Please enter Account ID" << endl;
            getline(cin, ID);
            if (ID.empty()){
                getline(cin, ID);
            }
            cout << "Please enter PIN" << endl;
            getline(cin, PIN);
            account = bank.findAcct(ID, PIN);
            // If user's account is found
            if (account.getAccountPin().empty()){
                cout << ID << " " << PIN << endl;
                cout << "Sorry - no match" << endl;
                counter++;
            } else {
                break;
            }
        }
        // Failed to login 3 times
        if (counter == 3){
            return 1;
        }
        // Continue to Transactions If Account Found
        cout << "Account found" << endl;
        transactions(account);
        return 0;
    } else if (answer == "Q"){
        return 0;
    } else {
        cout << "Unrecognized command " << answer << endl;
        start();
        return 0;
    }
}

void ATM::transactions(Account &acct) {
    cout << "Please enter your selection or Q to quit" << endl;
    cout << endl;
    cout << "W   - withdraw funds" << endl;
    cout << "D   - deposit funds" << endl;
    cout << "B   - check balance" << endl;
    cout << "Q   - quit/exit" << endl;

    string choice;
    cin >> choice;
    if (choice == "W"){
        double amount;
        cout << "Please enter amount of withdrawal" << endl;
        cin >> amount;
        acct.withdraw(amount);
    } else if (choice == "D"){
        double amount;
        cout << "Please enter amount of deposit" << endl;
        cin >> amount;
        acct.deposit(amount);
    } else if (choice == "B"){
        acct.Balance();
    } else if (choice == "Q"){
        cout << "Goodbye." << endl;
        start();
        return;
    } else {
        cout << "Unrecognized command " << choice << endl;
    }

    transactions(acct);
}

