#ifndef ARRAY_HPP
#define ARRAY_HPP

class Array
{
private:
    unsigned int a[];
public:
    Array();
    Array(unsigned int n);
    Array(Array const & src);
    Array &operator=(Array const & src);
};

#endif