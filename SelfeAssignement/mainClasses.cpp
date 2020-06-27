#include <iostream>
#include "classes.h"

int main(){
Color x(1,0,0), y(0,1,1);
Color z = x.add(y);
return 0;
}