#include <iostream>
#include "whatever.hpp"

int	extra( void )
{



	// INT
	int			n1 = 43;
	int			n2 = -12;

	// FLOAT
	float		f1 = 0.0f;
	float		f2 = -475.14f;

	// STRING
	std::string	s1 = "hello";
	std::string	s2 = "hello1";

	// CHAR
	char		c1 = 'a';
	char		c2 = 'b';

	// DOUBLE
	double		d1 = 4.4;
	double		d2 = 4.0;

    std::cout<<::max(s1, s2)<<std::endl;
    ::swap(s1, s2);
    std::cout<<s1<<std::endl;

    std::cout<<::min(d1, d2)<<std::endl;
    ::swap(d1, d2);
    std::cout<<d1<<std::endl;

    std::cout<<::max(c1, c2)<<std::endl;
    ::swap(c1, c2);
    std::cout<<c1<<std::endl;
	return (0);
}

int main( void )
{
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    extra();
    return 0;
}
