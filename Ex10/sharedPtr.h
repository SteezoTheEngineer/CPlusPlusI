#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include <iostream> 
using namespace std; 


template <typename T>
class sharedPtr
{
    private:
        T* m_ptr = nullptr;
        int *m_refCount = nullptr;
public:

    sharedPtr(){}

    sharedPtr(T* ptr)
    {
		m_ptr = ptr; 
		m_refCount = new int; 
        *m_refCount = 1;
    }
    ~sharedPtr()
    {
        reset();
        //cout << "Delete shared pointer" << endl;
    }

    int useCount(){
        if(m_refCount != nullptr)
            return *m_refCount;

        else
            return 0;
    }

    void reset(){
    if(m_refCount != nullptr && m_ptr != nullptr){

            if(*m_refCount <= 1){
                delete m_ptr;
                delete m_refCount;
                m_ptr = nullptr;
                m_refCount = nullptr;
            }

            else{
                --(*m_refCount);
                m_refCount = nullptr;
                m_ptr = nullptr;
            }
        }
        m_refCount = nullptr;
    }

    // Copy constructor
    sharedPtr(sharedPtr& copy)
    {
        if (this != &copy){
            reset();
            m_ptr = copy.m_ptr;
            m_refCount = copy.m_refCount;
            (*m_refCount)++;
        }
    }
    // Move constructor
    sharedPtr(sharedPtr&& move)
    {
        if (this != &move){
            reset();
            m_ptr = move.m_ptr;
            m_refCount = move.m_refCount;
            (*m_refCount)++;
            move.reset();
        }
    }
    // Copy assignment
    sharedPtr operator=(sharedPtr& copy)
    {
        if (this == &copy)
            return *this;
        else{
            reset();
            m_ptr = copy.m_ptr;
            m_refCount = copy.m_refCount;
            (*m_refCount)++;
            return *this;
        }
    }
    // Move assignment
    sharedPtr& operator=(sharedPtr&& move)
    {
        if (this == &move)
            return *this;
        else{
            reset();
            m_ptr = move.m_ptr;
            m_refCount = move.m_refCount;
            (*m_refCount)++;
            move.reset();
            return *this;
        }
    }

    T& operator*() { return *m_ptr; }
    T* operator->() { return m_ptr; }
    

};

#endif //SHAREDPTR_H