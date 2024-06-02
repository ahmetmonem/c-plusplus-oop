#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 _fix_int;
    static const int    _fractional_bits = 8;
public:
    Fixed();
    Fixed(const int x_i);
    Fixed(const float x_f);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    
    float   toFloat( void ) const;
    int     toInt(void) const;
    
};
std::ostream& operator<<(std::ostream& o, Fixed const &i) ;

#endif