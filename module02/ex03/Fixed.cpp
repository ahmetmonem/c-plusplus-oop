#include "Fixed.hpp"

Fixed::Fixed() :_fix_int(0)
{
    //std::cout<<"Default constructor called"<<std::endl;
}

Fixed::~Fixed()
{
    //std::cout<<"Destructor called"<<std::endl;
}

Fixed::Fixed(const int x_i) : _fix_int(x_i << _fractional_bits)
{
    //std::cout<<"Int constructor called"<<std::endl;
}

Fixed::Fixed(const float x_f) : _fix_int(std::roundf( x_f * ( 1 << _fractional_bits)))
{
    //std::cout<<"Float constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& other) : _fix_int(other._fix_int)
{
    //std::cout<<"Copy constructor called"<<std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    //std::cout<<"Copy assignment operator called"<<std::endl;
    if (this != &other)
    {
        this->_fix_int = other._fix_int;
    }
    return *this;
}

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return this->_fix_int;
}

void Fixed::setRawBits(int const raw)
{
    this->_fix_int = raw;
}

float Fixed::toFloat(void) const 
{
    return static_cast<float>(this->_fix_int) / (1 << _fractional_bits);
}

int Fixed::toInt(void) const 
{
    return this->_fix_int >> _fractional_bits;
}

std::ostream& operator<<(std::ostream& out, Fixed const &i)
{
    out << i.toFloat();
    return out;
}

bool    Fixed::operator>(const Fixed& com) const
{
    return (this->_fix_int > com._fix_int);
}

bool    Fixed::operator<(const Fixed& com) const
{
    return (this->_fix_int < com._fix_int);
}

bool    Fixed::operator>=(const Fixed& com) const
{
    return (this->_fix_int >= com._fix_int);
}

bool    Fixed::operator<=(const Fixed& com) const
{
    return (this->_fix_int <= com._fix_int);
}

bool    Fixed::operator==(const Fixed& com) const
{
    return (this->_fix_int == com._fix_int);
}

bool    Fixed::operator!=(const Fixed& com) const
{
    return (this->_fix_int != com._fix_int);
}

Fixed   Fixed::operator+(const Fixed &com) const {
    return Fixed(this->toFloat() + com.toFloat());
}

Fixed   Fixed::operator-(const Fixed &com) const {
    return Fixed(this->toFloat() - com.toFloat());
}

Fixed   Fixed::operator*(const Fixed &com) const {
    return Fixed(this->toFloat() * com.toFloat());
}

Fixed   Fixed::operator/( const Fixed &com ) const {
    return Fixed(this->toFloat() / com.toFloat());
}

Fixed&  Fixed::operator++(void)
{
    ++this->_fix_int;
    return *this;
}

Fixed  Fixed::operator++(int)
{
    Fixed temp(*this);
    temp._fix_int = this->_fix_int++;
    return temp;
}

Fixed&  Fixed::operator--(void)
{
    --this->_fix_int;
    return *this;
}

Fixed  Fixed::operator--(int)
{
    Fixed temp(*this);
    temp._fix_int = this->_fix_int--;
    return temp;
}

Fixed&  Fixed::min(Fixed& f, Fixed& s)
{
    return (f._fix_int < s._fix_int) ? f : s;
}

const Fixed&  Fixed::min(const Fixed& f, const Fixed& s)
{
    return (f._fix_int < s._fix_int) ? f : s;
}

Fixed&  Fixed::max(Fixed& f, Fixed& s)
{
    return (f._fix_int > s._fix_int) ? f : s;
}

const Fixed&  Fixed::max(const Fixed& f, const Fixed& s)
{
    return (f._fix_int > s._fix_int) ? f : s;
}

