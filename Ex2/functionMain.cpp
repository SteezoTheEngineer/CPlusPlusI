#include <iostream>


#include "calculatorPrint.h" // <- Todo: Declare & Implement the function add, addNumbers, printType in the
                             //          files calculatorPrint.h/.cpp



int main ()
{
    // Code for 2.1.1
    int nbr1;
    int nbr2;

    std::cout << "Enter two numbers: ";
    std::cin >> nbr1 >> nbr2;
    int sum = add(nbr1, nbr2);
    std::cout << std::endl << "The sum is " << sum << "." << std::endl;


    // Code for 2.1.2
    int res;
    add(nbr1, nbr2, res);
    std::cout << "The reference sum is " << res << "." << std::endl;


    if(sum != res)
        std::cout << "Error: There is an issue with one of the two add(... functions" << std::endl;



    // Todo: Answer question 2.1.2
    // The variable shoud be declared by reference => void doubleNumber ( int& num ){ num = num * 2;}



    // Code for 2.2

    std::cout << "Result of addNumbers(1, 2, 3, 4): "  << addNumbers(1, 2, 3, 4) << std::endl;
    std::cout << "Result of addNumbers(1, 2, 3):    "  << addNumbers(1, 2, 3) << std::endl;
    std::cout << "Result of addNumbers(1, 2):       "  << addNumbers(1, 2) << std::endl;
    std::cout << "Result of addNumbers(1):          "  << addNumbers(1) << std::endl;
    std::cout << "Result of addNumbers():           "  << addNumbers() << std::endl;
    



    if( addNumbers(1, 2, 3, 4) != 10 )
        std::cout << std::endl << "Error: There is an issue with  addNumbers(1, 2, 3, 4)" << std::endl;
    if( addNumbers(1, 2, 3) != 6 )
        std::cout << std::endl << "Error: There is an issue with  addNumbers(1, 2, 3)" << std::endl;
    if( addNumbers(1, 2) != 3 )
        std::cout << std::endl << "Error: There is an issue with  addNumbers(1, 2)" << std::endl;
    if( addNumbers(1) != 1 )
        std::cout << std::endl << "Error: There is an issue with  addNumbers(1)" << std::endl;
    if( addNumbers() != 0 )
        std::cout << std::endl << "Error: There is an issue with  addNumbers(1)" << std::endl;

    


    // Code for 2.3

    
    printType(1);
    printType(1.0f);
    printType(1.0);
    printType("CLion");


    return 0;
}

 /*
 If everything works out good, the program prints out: >


    Enter two numbers: 2 4

    The sum is 6.
    The reference sum is 6.

    Output for 2.3
    Type is int
    Type is float
    Type is double
    Type is string

    Process finished with exit code 0

 */
