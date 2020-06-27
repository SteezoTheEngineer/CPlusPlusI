#include <iostream>

int h(int v){
    return 3*v; // v is not changed and still 1
}
int g(int *v){ // intput is the pointer adress
    return *v *=2; // the vlaue at the adress of v is set to 2
}

int f(int &v) 
{
    return v +=4; // f(v) adds 4 to 2 and h(v) multipies it with 3 = 18
}
int main(){
    int v = 1;
    std::cout << h(v) << std::endl; // 3
    std::cout << g(&v) << std::endl; // 2
    std::cout << h(f(v)) << std::endl; // 18
    return 0;
}