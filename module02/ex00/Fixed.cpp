#include "fixed.hpp"

Fixed::Fixed() :_fix_int(0)
{
    std::cout<<"Default constructor called"<<std::endl;
}

Fixed::~Fixed()
{
    std::cout<<"Destructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& other) : _fix_int(other._fix_int)
{
    std::cout<<"Copy constructor called"<<std::endl;

}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout<<"Copy assignment operator called"<<std::endl;
    if (this != &other)
    {
        this->_fix_int = other._fix_int;
    }
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fix_int;
}

void Fixed::setRawBits(int const raw)
{
    this->_fix_int = raw;
}