#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <cmath>
#include <cerrno>

class ScalarConverter {
public:
    static void convert(const std::string& input);

private:
    static bool isChar(const std::string& s);
    static bool isInteger(const std::string& s);
    static bool isFloat(const std::string& s);
    static bool isDouble(const std::string& s);

    static void printIntAsChar(int i);
    static void printFloatAsChar(float f);
    static void printDoubleAsChar(double d);

    static void printFloatAsInt(float f);
    static void printDoubleAsInt(double d);
};

#endif