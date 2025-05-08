#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* Base::generate()
{
    int r = rand() % 3;

    if (r == 0)
        return new A;
    else if (r == 1)
        return new B;
    else
        return new C;
}

void Base::identify(Base* p) 
{
    if(dynamic_cast<A*>(p))
        std::cout <<"A"<< std::endl;
    if(dynamic_cast<B*>(p))
        std::cout <<"B"<< std::endl;
    if(dynamic_cast<C*>(p))
        std::cout <<"C"<< std::endl;
}

void Base::identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
    }
    catch (...) 
    {
        try
        {
            (void)dynamic_cast<B&>(p);
            std::cout << "B\n";
        }
        catch (...)
        {
        try
        {
                (void)dynamic_cast<C&>(p);
                std::cout << "C\n";
        }
        catch (...)
        {
                std::cout << "Unknown\n";
        }
        }
    }
}

Base::~Base(){}
