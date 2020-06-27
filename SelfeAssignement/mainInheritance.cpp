#include <iostream>
#include "inheritance.h"

int main(){
    ColorA a(1,0,0,0.5), b(0,0,1,0.5);
    ColorA c = a.add(b);
    return 0;
}
