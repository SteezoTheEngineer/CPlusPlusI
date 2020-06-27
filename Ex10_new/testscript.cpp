#include <iostream>
#include "uniquePtr.h"
#include "sharedPtr.h"

using namespace std;

uniquePtr<double> checkMove(uniquePtr<double> UP)
{
    *UP += 1;
    return UP;
}

struct A
{
    A(string name):m_name(name) {}
    string m_name;
};

int main()
{
    cout << "*** Test Unique Pointer ***" << endl << endl;
    uniquePtr<double> up1(new double(3.1415));
    cout << "Value of up1 -> " << *up1 << " = 3.1415" << endl << endl;

    uniquePtr<A> Aptr(new A("Member Access Operator")) ;
    cout << Aptr->m_name << endl << endl;


    {   // Create scope to check move-assign
        uniquePtr<double> up2(new double(23));
        cout << "Value of up2 -> " << *up2 << " = 23" << endl << endl;
        up1 = std::move(up2);
    }
    cout << "Value of up1 after move -> " << *up1 << " = 23" << endl << endl;
    uniquePtr<double> up2 = checkMove(std::move(up1));
    cout << "Value of up1 after check move: " << *up2 << " = 24" << endl << endl;


    cout << "*** Test SharedPointer ***" << endl << endl;

    sharedPtr<int> sp1;
    cout << "Use count of sp1 -> " << sp1.useCount() << " = 0" << endl << endl;

    sharedPtr<int> sp2(new int(42));
    cout << "Use count of sp2 -> " << sp2.useCount() << " = 1" << endl;
    cout << "Value of sp2 is -> " << *sp2 << " = 42" << endl << endl;

    {  // Create scope to check copy constructor
        sharedPtr<int> sp3(sp2);
        cout << "Use count after copy -> sp2: " << sp2.useCount() << " = 2," << " sp3: " << sp3.useCount() << " = 2" << endl;
        cout << "Values after copy -> sp2: " << *sp2 << " = 42," << " sp3: " << *sp3  << " = 42" << endl << endl;
    }
    cout << "Use count of sp2 -> " << sp2.useCount() << " = 1" << endl << endl;

    // Check assignment operator call
    sp1 = sp2;
    cout << "Use count after copy assign ->  sp2: " << sp2.useCount() << " = 2," << " sp1: " << sp1.useCount() << " = 2" << endl;
    cout << "Values after copy assign ->  sp2: " << *sp2 << " = 42," << " sp1: " << *sp1 << " = 42" << endl << endl;


    {   // Create scope to check move-assign
        sharedPtr<int> sp4(new int(1414));
        sp1 = std::move(sp4);
        cout << "Use count after move assign ->  sp4: " << sp4.useCount() << " = 0," << " sp1: " << sp1.useCount() << " = 1" << endl;
    }

    // Reset
    sp1.reset();
    sp2.reset();
    cout << "Use count of sp1 -> " << sp2.useCount() << " = 0" << endl;
    cout << "Use count of sp2 -> " << sp2.useCount() << " = 0" << endl;

    return 0;
}
