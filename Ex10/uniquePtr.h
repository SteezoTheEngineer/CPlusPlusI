#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H

template <typename T>
class uniquePtr
{
    private:
        T* rawPtr = nullptr;
    public:
        uniquePtr(T* _rawPtr) : rawPtr(_rawPtr){}

        ~uniquePtr(){
               delete rawPtr;
               //std::cout<<"Delete unique pointer"<<std::endl;
            };

        uniquePtr(const uniquePtr&) = delete;
        uniquePtr& operator=(const uniquePtr&) = delete;


        T& operator* ()
        {
        return *rawPtr;
        };

         T* operator-> ()
        {
        return rawPtr;
        }

       
        
        uniquePtr(uniquePtr&& move) // move constructor
        {
            if(move.rawPtr != nullptr){
                rawPtr = move.rawPtr;
                move.rawPtr = nullptr;
            }
        }

        uniquePtr& operator= (uniquePtr&& move) // move assignement operator
        {
            if((move.rawPtr != nullptr) && (this != &move))
            {
            delete[] rawPtr;

            rawPtr = move.rawPtr;
            move.rawPtr = nullptr;
        }
        return *this;
        } 
};


template <typename T>
class uniquePtr<T[]>
{
    private:
        T* rawPtr{nullptr};
    public:
        uniquePtr(T* _rawPtr) : rawPtr(_rawPtr){}

        ~uniquePtr(){
                delete[] rawPtr;
            };

        uniquePtr(const uniquePtr&) = delete;
        uniquePtr& operator=(const uniquePtr&) = delete;


        T& operator* ()
        {
        return *rawPtr;
        };

         T* operator-> ()
        {
        return rawPtr;
        }

       
        
        uniquePtr(uniquePtr&& move) // move constructor
        {
            if(move.rawPtr != nullptr){
                rawPtr = move.rawPtr;
                move.rawPtr = nullptr;
            }
        }

        uniquePtr& operator= (uniquePtr&& move) // move assignement operator
        {
            if((move.rawPtr != nullptr) && (this != &move))
            {
            delete[] rawPtr;

            rawPtr = move.rawPtr;
            move.rawPtr = nullptr;
        }
        return *this;
        } 
};

#endif //UNIQUEPTR_H