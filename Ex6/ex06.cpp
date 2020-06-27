#include <iostream>
#include "checkingaccount.h"

/* 2.2
a) 
The output is:
Base ()
Derived ()
~ Derived ()
~ Base ()

b)
m_x can not be printed because it's declared as private in the base
*/


int main()
{
    CheckingAccount myAccount(1000, 0.5); // initial amount and fee
    myAccount.credit(250);    // ok
    myAccount.printBalance(); // -> 1250
    myAccount.debit(1000);    // ok
    myAccount.printBalance(); // -> 249.5
    myAccount.debit(249.5);   // Waring: Not enough funds
    myAccount.debit(249);     // ok
    myAccount.printBalance(); // -> 0

    return 0;
}


