#include <iostream>

class burger 
{
    private: 
    int m_count = 0;

    public:
    burger(){};
    int size(){
        return m_count;
    }
};

burger v1;

int main() {
    
    burger v1;
    std::cout<<v1.size()<<std::endl;
    return 0;
}