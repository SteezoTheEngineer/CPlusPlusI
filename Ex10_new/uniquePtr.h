#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H

template <typename T>
class uniquePtr
{
    private:
        T* m_rawPtr;
    
    public:
        // constructor if no input is given set nullprt
        uniquePtr():m_rawPtr(nullptr){}
        // constructor if input is given set given prt as m_rawPtr
        uniquePtr(T* rawPrt):m_rawPtr(rawPrt){}
        // deconstructor delete m_rawPtr
        ~uniquePtr(){
            delete m_rawPtr;
        }

        // disable copy constructor 
        uniquePtr(const uniquePtr& copy) = delete;
        // disable copy assignment operator
        uniquePtr& operator=(const uniquePtr &);

        //operator overloading for dereference operator *
        T& operator*(){
            return *(m_rawPtr);
        }

        //operator overloading for dereference operator ->
        T* operator->(){
            return m_rawPtr;
        }

        //Move constructor could also be done with initalisation list uniquePtr(uniquePtr&& move):m_rawPtr(move.m_rawPtr)
        uniquePtr(uniquePtr&& move){
            m_rawPtr = move.m_rawPtr;
            move.m_rawPtr = nullptr;
        }

        //Move assignment opeartor
         uniquePtr& operator=(uniquePtr&& move){
            // object exsists thats why we have to check if its not a nullprt-> memory leak
            if(m_rawPtr != nullptr){
                delete m_rawPtr;
            }
            m_rawPtr = move.m_rawPtr;
            move.m_rawPtr = nullptr;
            return *this;
        }

};

template <typename T>
class uniquePtr <T[]>
{
    private:
        T* m_rawPtr;
    
    public:
        // constructor if no input is given set nullprt
        uniquePtr():m_rawPtr(nullptr){}
        // constructor if input is given set given prt as m_rawPtr
        uniquePtr(T* rawPrt):m_rawPtr(rawPrt){}
        // deconstructor delete m_rawPtr
        ~uniquePtr(){
            delete[] m_rawPtr;
        }

        // disable copy constructor 
        uniquePtr(const uniquePtr& copy) = delete;
        // disable copy assignment operator
        uniquePtr& operator=(const uniquePtr &);

        //operator overloading for dereference operator *
        T& operator*(){
            return *(m_rawPtr);
        }

        //operator overloading for dereference operator ->
        T* operator->(){
            return m_rawPtr;
        }

        //Move constructor could also be done with initalisation list uniquePtr(uniquePtr&& move):m_rawPtr(move.m_rawPtr)
        uniquePtr(uniquePtr&& move){
            m_rawPtr = move.m_rawPtr;
            move.m_rawPtr = nullptr;
        }

        //Move assignment opeartor
         uniquePtr& operator=(uniquePtr&& move){
            // object exsists thats why we have to check if its not a nullprt-> memory leak
            if(m_rawPtr != nullptr){
                delete m_rawPtr;
            }
            m_rawPtr = move.m_rawPtr;
            move.m_rawPtr = nullptr;
            return *this;
        }

};


#endif //UNIQUEPTR_H