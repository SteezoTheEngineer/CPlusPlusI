#include <iostream>
int add(int nbr1, int nbr2){
    return nbr1 + nbr2;
}
void add(int nbr1, int nbr2, int& res){
    res = nbr1 + nbr2;
}

int addNumbers(int a, int b, int c, int d){
    return a + b + c + d;
}

void printType(int in){
    std::cout << "Type is int "<< std::endl;
}

void printType(double in){
    std::cout << "Type is double "<< std::endl;
}

void printType(float in){
    std::cout << "Type is float "<< std::endl;
}

void printType(const char* in){
    std::cout << "Type is string "<< std::endl;
}

