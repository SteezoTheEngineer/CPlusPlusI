#include <iostream>
class A
{
public:
    int m_v = 5;
    int m_u = 2;
    int m_w;

    A() : m_v{1}, m_w{2} {m_u++;}
    A(const A &a): m_w{a.m_w}{}
    A(A &&a): m_v{a.m_v}, m_w{m_u} {--m_u;}
};

int main(){
    A v1;
    A v2(v1);
    A v3(std::move(v1));
    std::cout << v1.m_v << ',' << v1.m_w << ',' << v1.m_u << std::endl;
    std::cout << v2.m_v << ',' << v2.m_w << ',' << v2.m_u << std::endl;
    std::cout << v3.m_v << ',' << v3.m_w << ',' << v3.m_u << std::endl;

}