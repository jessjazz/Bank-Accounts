#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
//    
    // Account frank{"Frank", 5000};         // should not compile
    // cout << frank << endl;
    Savings_Account harry {"Harry", 10000, 10.0};
    cout << harry << endl;
    harry.deposit(500);
    cout << harry << endl;
    
    Trust_Account hermione {"Hermione", 26250};
    cout << hermione << endl;
    hermione.withdraw(1000);
    cout << hermione << endl;
    
    Checking_Account ron {"Ron", 5000};
    cout << ron << endl;
    
    Account *trust = new Trust_Account("James");
    cout << *trust << endl;
    
    Account *p1 = new Checking_Account("Larry", 10000);
    Account *p2 = new Savings_Account("Moe", 1000);
    Account *p3 = new Trust_Account("Curly");
    
    std::vector<Account *> accounts {p1,p2,p3};
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);
    
    display(accounts);
    
    delete p1;
    delete p2;
    delete p3;
    return 0;
}

