#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>


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

#endif // VECTOR_H