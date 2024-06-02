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

    bool    operator>(const Fixed& com) const;
    bool    operator<(const Fixed& com) const;
    bool    operator>=(const Fixed& com) const;
    bool    operator<=(const Fixed& com) const;
    bool    operator==(const Fixed& com) const;
    bool    operator!=(const Fixed& com) const;
    Fixed   operator+(const Fixed& com) const;
    Fixed   operator-(const Fixed& com) const;
    Fixed   operator*(const Fixed& com) const;
    Fixed   operator/(const Fixed& com) const;
    Fixed&  operator++(void);
    Fixed   operator++(int);
    Fixed&  operator--(void);
    Fixed   operator--(int);

    static Fixed&          min(Fixed& f, Fixed& s);
    static const Fixed&    min(const Fixed& f, const Fixed& s);
    static Fixed&          max(Fixed& f, Fixed& s);
    static const Fixed&    max(const Fixed& f, const Fixed& s);
};
std::ostream& operator<<(std::ostream& o, Fixed const &i) ;

#endif