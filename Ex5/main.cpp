#include <iostream>
using namespace std;

#include "vector.h" // Your implementation of vector


int main(int argc, char *argv[])
{
    cout << " ***************************** " << endl;
    cout << " ******** VECTOR TEST-2 ******** " << endl;
    cout << " *****************************\n" << endl;

    // 1) Initialisation
    Vector v1; // empty vector
    Vector v2(100); // vector with 100 elements initialised to 0!
    Vector v3(100, 42) ; // vector with 100 elements initialised to 42!

    cout << "v1 has size " << v1.size() << endl;
    cout << "v2 has size " << v2.size() << endl;
    cout << "v3 has size " << v3.size() << "\n" << endl;

    // 2) Element access
    cout << "v1 contains value: " << v1.at(0) << endl; // -> warning ! --> without correction an old value in the memory is returned
    cout << "v2 contains value: " << v2.at(0) << endl;
    cout << "v3 contains value: " << v3.at(0) << endl;
    cout << "v3 contains value: " << v3.at(142) << endl; // -> warning ! --> without correction an old value in the memory is returned

    // 3) Add Element
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    cout << "\n" << "v1 has size " << v1.size() << " and contains: " << endl;

    for (int i = 0; i < v1.size(); ++i)
    {
        cout << i << ": " << v1.at(i) << endl;
    }

    // 4) Remove Element
    v1.pop_back();
    v1.pop_back();

    cout << "\n" << "v1 has size " << v1.size() << " and contains: " << endl;

    for (int i = 0; i < v1.size(); ++i)
    {
        cout << i << ": " << v1.at(i) << endl;
    }

    // 4) Clear Elements
    v1.clear();
    cout << "\n" << "v1 has size " << v1.size() << endl;

    // 5) Check Copy Constructor
    Vector vCopy(v3);
    cout << "vCopy has size " << vCopy.size() << "\n" << endl;
    cout << "vCopy contains value: " << vCopy.at(0) << "\n" << endl;

    // 6) Check Move Constructor
    Vector vMove = move(v3);
    cout << "vMove has size " << vMove.size() << "\n" << endl;
    cout << "vMove contains value : " << vMove.at(0) << "\n" << endl;

    cout << "v3 has size " << v3.size () << "\n" << endl;
/*
    // 7) Check Copy Assignment Operator <<Operator
    vMove = vMove; // Copy assign - Check Self-Assignment
    cout << "Self Assigned Copy has size " << vMove.size()  << endl;
    cout << "Self Assigned Copy contains value " << vMove.at(0) << "\n" << endl;

    v2 = vMove; // Copy assign
    cout << "Assigned Copy has size " << v2.size() << endl;
    cout << "Assigned Copy contains value " << v2 << "\n" << endl;

    // 8) Check Move Assignment Operator and <<Operator
    v2 = v2 + vMove; // Move assign!
    cout << "Vector Addition has size " << v2.size() << endl;
    cout << "Vector Addition contains value\n" << v2 << "\n" << endl; // --> 84

    v3 = v2 * v2; // Move assign!
    cout << "Vector Multiplication has size " << v3.size() << endl;
    cout << "Vector Multiplication contains values\n" << v3 << "\n" << endl; // --> 7056
    */

    cout << " ***************************** " << endl;
    cout << " **** VECTOR TEST-2 PASSED ***** " <<  endl;
    
    return 0;
}
