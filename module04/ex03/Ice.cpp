#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    // std::cout<<"Ice constructed"<<std::endl;
}

Ice::~Ice()
{
    // std::cout<<"Ice destructed"<<std::endl;
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout<<"* shoots an ice bolt at "<<target.getName()<<" *"<<std::endl;
}


Ice::Ice(Ice const & other) : AMateria("ice")
{
    *this = other;
}


Ice&   Ice::operator=(const Ice& other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}