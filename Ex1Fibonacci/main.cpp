#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
#include "fibonacci.h"

using namespace std;

int main()
{
    int f = 1;
    int fprev = 0;
    int counter = 0;
    double ratio = 0;
    double trueRatio = (1+sqrt(5))/2;;
    double relError = 0;

    cout << "The limit of a integer is: " << numeric_limits<int>::max() << endl;

    cout <<"Fibonacci Number: "<<fprev << endl;

    do {
        cout << "Fibonacci Number: "<< f << endl;
        int tmp = fibonacci(f, fprev);

        fprev = f;
        f = tmp;

        ratio = static_cast<double>(f)/static_cast<double>(fprev);
        relError = (1-ratio/trueRatio)*100;

        counter += 1;

        cout << "Ratio:    " <<setprecision(17)<< fixed <<ratio<<"- Dev[%]:    "<< setprecision(17)<< fixed << relError << endl;


    } while (f >= fprev );
    cout << counter << " loops are computed" << endl;
    cout << "To compute larger fibonacci numbers the data type has to be changed.(unsigned int, long int, unsigned long int, long long int, unsigned long long int)" << endl;
    cout << endl;
    return 0;
}

