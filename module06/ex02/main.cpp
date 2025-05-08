#include "Base.hpp"

int main()
{
    Base* p;
    srand(time(0));
    p = Base::generate();
    Base::identify(p);
    p = Base::generate();
    Base::identify(p);
    p = Base::generate();
    Base::identify(p);
    p = Base::generate();
    Base::identify(p);
    
    p = Base::generate();
    Base::identify(*p);
    
    delete p;
    return 0;
}