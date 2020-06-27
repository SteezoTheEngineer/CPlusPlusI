#include "checkingaccount.h"
#include <iostream>


// ******** BASE ********************************************3

Account::Account(double Balance) : m_balance(Balance)
{

}


void Account::credit(double add)
{
    m_balance += add;
    std::cout << "The balance is "<< m_balance << std::endl;

}

void Account::debit(double sub)
{
    if(m_balance-sub >= 0){
    m_balance -= sub;
    }else{
    std::cout << "Not enough funds"<< std::endl;
    }
}

void Account::printBalance()
{
    std::cout << "The current balance is: "<< m_balance <<std::endl;
    
}

// ******** DERRIVED ***********************************************3

CheckingAccount::CheckingAccount(double Balance, double Fee) : Account(Balance), m_fee(Fee) // Calls base class constructor
{

}

void CheckingAccount::debit(double sub)
{
    if(m_balance-sub-m_fee >= 0){
    m_balance -= sub + m_fee;
    }else{
    std::cout << "Not enough funds"<< std::endl;
    }
}

