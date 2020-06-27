#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include <iostream> 

template <typename T>
class sharedPtr
{
private:
    T* m_rawPtr;
    int* m_count; 

public:
    // Constructor
    sharedPtr():m_rawPtr(nullptr), m_count(nullptr){}
    // Constructor with input
    sharedPtr(T* rawPtr):m_rawPtr(rawPtr), m_count(new int{1}){}
    // Destructor
    ~sharedPtr(){
        reset();
    }

    //Copy constructor
    sharedPtr(const sharedPtr& copy):m_rawPtr(nullptr), m_count(nullptr){
        reset();
        m_rawPtr = copy.m_rawPtr;
        m_count = copy.m_count;
        ++(*m_count);
    }

    // Copy assignement operator
    sharedPtr operator=(const sharedPtr& copy){
        reset();
        m_rawPtr = copy.m_rawPtr;
        m_count = copy.m_count;
        ++(*m_count);
        return *this;
    }

    // Move constructor
    sharedPtr(sharedPtr&& move){
        reset();
        m_rawPtr = move.m_rawPtr;
        m_count = move.m_count;
        move.reset();
        ++(*m_count);
    }

    // Move assignment operator
    sharedPtr& operator=(sharedPtr&& move){
        reset();
        m_rawPtr = move.m_rawPtr;
        m_count = move.m_count;
        move.reset();
        ++(*m_count);
        return *this;
    }

    T& operator*(){
        return *(m_rawPtr);
    }

    T* operator->(){
        return m_rawPtr;
    }

    int useCount(){
        if (m_count != nullptr){
            return *m_count;
        }
        else{
            return 0;
        }

    }

    void reset(){
        if(m_count != nullptr && m_rawPtr != nullptr){
            if(*m_count <= 1){
                delete m_rawPtr;
                delete m_count;
            }
            else{
                --(*m_count);
            }
            m_rawPtr = nullptr;
            m_count = nullptr;
        }
    }


    

};




#endif //SHAREDPTR_H