#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account {name, balance, int_rate}, withdraw_count{0} {
}

bool Trust_Account::deposit(double amount) {
    if (amount >= bonus_threshold) {
        amount += bonus;
    }
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
    if (amount < (balance * max_withdrawal_percent) && withdraw_count < max_withdrawals)
    {
        withdraw_count++;
        return Savings_Account::withdraw(amount);
    }
    else
        return false;
}

void Trust_Account::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Trust_Account: " << name << ": " << balance << ", Withdrawal count: " 
        << withdraw_count << " , Bonus: " << bonus << ", int_rate: " << int_rate << "]";
}