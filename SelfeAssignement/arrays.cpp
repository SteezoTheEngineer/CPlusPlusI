# include <iostream>

/*Wrong snippet

int* allocateArray(const int length)
{
    int temp[length];
    return temp;
}

*/
int* allocateArray(const int length){
    int *temp = new int[length];
    return temp;
}

int main(){
    std::cout<<allocateArray(5);
    return 0;
}