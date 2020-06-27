#include <iostream>

int main(){
    int x = 5;
    int y = 7;

    int* prt = &x; // pointer points to the adress of x
    std::cout << prt<<std::endl;
    *prt = 6; // value of the pointer which points to x is set 6
    std::cout << *prt << std::endl;
    std::cout << x << std::endl;
    prt = &y; // pointer points to the adress of y
    std::cout<< *prt<<std::endl; // value of the pointer is 7
    std::cout << y << std::endl;
    return 0;
}