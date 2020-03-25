#include <iostream>
using namespace std;

//#include "vector.h" // Your implementation of vector

class Vector
{
private:

    int* m_data = nullptr;
    int m_size;


public:
    
    Vector(){
        m_size = 0;
        m_data = new int[0];
    } 
    Vector(int size){
        m_size = size;
        m_data = new int[size];
        for (int i = 0; i < size; i++) {
        m_data[i]=0;
        }
    }
    Vector(int size, int value){
        m_size = size;
        m_data = new int[size];
        for (int i = 0; i < size; i++) {
        m_data[i]=value;
        }
    }
    Vector(const Vector& copy){
        if(copy.m_data != nullptr){
            m_data = new int [copy.m_size];
            m_size = copy.m_size;
            for (int i = 0; i < copy.m_size; i++) {
            m_data[i] = copy.m_data[i];
            }
        }
    }
    Vector(Vector&& move){
        if(move.m_data != nullptr){
            m_size = move.m_size;
            m_data = move.m_data;
            move.m_data = nullptr;
            move.m_size = 0;
        }
    }
    ~Vector(){
        delete[] m_data;
    }
        
    int size(){
        return m_size;
    }

     int at(int index){
        if (index>m_size or index<0){
            cout<<"The index is out of range";
            return -1;
        }
        else if(m_size == 0){
            cout<<"The vector is empty";
            return -1;
        }
        else{
            return m_data[index];
        }
    }

    void push_back(int newVal){
        int* new_m_data = new int [m_size+1];
        for (int i = 0; i < m_size; i++) {
        new_m_data[i] = m_data[i];
        }
        new_m_data[m_size] = newVal;
        delete [] m_data;
        m_data = new_m_data;
        m_size++;
    }

    void pop_back(){
        int* new_m_data = new int [m_size-1];
        for (int i = 0; i < m_size-1; i++) {
        new_m_data[i] = m_data[i];
        }
        delete [] m_data;
        m_data = new_m_data;
        m_size--;
    }

    void clear(){
        int* new_m_data = nullptr;
        delete [] m_data;
        m_data = new_m_data;
        m_size = 0;
    }

};



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
