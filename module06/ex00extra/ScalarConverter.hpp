#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

template <typename T>

class ScalarConverter
{
public:
    static T convert(std::string var);
};
#include "ScalarConverter.cpp"
#endif