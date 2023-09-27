#include <iostream>
#include <fstream>
#include "Bank.h"
#include "ATM.h"
#include "Account.h"
#include <string>
using namespace std;
int main() {
    Bank bk;
    cout << "Enter path for account information: ";
    string location;
    cin >> location;
    ifstream inf(location);
    cout << "Loading Data..." << endl;
    bk.loadAccounts(inf);
    ATM ATM(bk);
    int result = ATM.start();
    if (result == 0){
        cout << "Normal Exit." << endl;
    } else {
        cout << "Account not found - system shutting down" << endl;
    }

    return 0;
}
