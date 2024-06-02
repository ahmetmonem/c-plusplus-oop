#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    // std::cout<<"Cure constructed"<<std::endl;
}

Cure::Cure(Cure const & other) : AMateria("cure")
{
    *this = other;
}

Cure::~Cure()
{
    // std::cout<<"Cure destructed"<<std::endl;
}

Cure&   Cure::operator=(const Cure& other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

AMateria*   Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout<<"* heals "<<target.getName()<<"'s wounds *"<<std::endl;
}