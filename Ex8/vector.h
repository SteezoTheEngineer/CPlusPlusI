#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <string.h>
#include <sstream>


class Vector
{
private:

    int* m_data = nullptr;
    int m_size;
    string m_output;


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
    Vector(const Vector& copy) //copy constructor
    {
        if(copy.m_data != nullptr){
            m_data = new int [copy.m_size];
            m_size = copy.m_size;
            for (int i = 0; i < copy.m_size; i++) {
            m_data[i] = copy.m_data[i];
            }
        }
        else
            m_data = NULL;
    }

     Vector& operator=(const Vector& copy)  // copy assignement opperatro
    {
        if ((this != &copy) && (copy.m_data != nullptr))
        {
            if (m_data != nullptr)
            delete[] m_data;
            // ensure deep copy by first allocating own buffer
            m_data = new int [copy.m_size + 1];
            // copy from the source in to local buffer
           for (int i = 0; i < copy.m_size; i++) {
            m_data[i] = copy.m_data[i];
            }
        }
        return *this;
    }    



    
    Vector(Vector&& move) // move constructor
    {
        if(move.m_data != nullptr){
            m_size = move.m_size;
            m_data = move.m_data;
            move.m_data = nullptr;
            move.m_size = 0;
        }
    }

    Vector& operator= (Vector&& move) // move assignement operator
    {
        if((move.m_data != nullptr) && (this != &move))
        {
            delete[] m_data;

            m_data = move.m_data;
            m_size = move.m_size;
            move.m_data = nullptr;
        }
        return *this;
    } 

    
    operator const char*()
    {
        std::stringstream formattedOutput; // for string cnstruction
        
        if (m_size != 0){
            formattedOutput << m_data[0];
            if (m_size < 5){
            for (int i = 1; i < m_size; i++) {
                formattedOutput << ", " << m_data[i] ;
                }
            }else{
                for (int i = 1; i < 5; i++) {
                formattedOutput << ", " << m_data[i] ;
                }
            }
        }
        m_output = formattedOutput.str(); // create copy to member !
        return m_output.c_str(); // return const char *
    }


     // Overload + operator to add two Box objects.
      Vector operator +(const Vector& add) {
        
        Vector vNew(m_size);
        if(add.m_data != nullptr)
        {
         for(int i = 0; i < m_size; i++){
         vNew.m_data[i] =  m_data[i] + add.m_data[i];
         }
        }
         return vNew;
      }


    // Overload * operator to add two Box objects.
      Vector operator *(const Vector& multiply) {
        
        Vector vNew(m_size);
        if(multiply.m_data != nullptr)
        {
         for(int i = 0; i < m_size; i++){
         vNew.m_data[i] =  m_data[i] * multiply.m_data[i];
         }
        }
         return vNew;
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

#endif // VECTOR_H