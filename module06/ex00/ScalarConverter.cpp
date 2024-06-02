#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& input)
{
    // try {
        if (isChar(input)) {
            char c = input[0];
            std::cout << "char: '" << c << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(c) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(c) << std::endl;
        } else if (isInteger(input)) {
            int i = std::stoi(input);
            printIntAsChar(i);
            std::cout << "int: " << i << std::endl;
            std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(i) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(i) << std::endl;
        } else if (isFloat(input)) {
            float f = std::stof(input);
            printFloatAsChar(f);
            std::cout << "int: ";
            printFloatAsInt(f);
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(f) << std::endl;
        } else if (isDouble(input)) {
            double d = std::stod(input);
            printDoubleAsChar(d);
            std::cout << "int: ";
            printDoubleAsInt(d);
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
        } else {
            throw std::invalid_argument("Invalid literal");
        }
    // } catch (const std::invalid_argument& e) {
    //     std::cerr << e.what() << std::endl;
    // } catch (const std::out_of_range& e) {
    //     std::cerr << "Out of range" << std::endl;
    // }
}

bool ScalarConverter::isChar(const std::string& s)
{
    return s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]);
}

bool ScalarConverter::isInteger(const std::string& s)
{
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;
    char* p;
    errno = 0;
    long int l = strtol(s.c_str(), &p, 10);
    return (*p == 0 && errno == 0 && l >= std::numeric_limits<int>::min() && l <= std::numeric_limits<int>::max());
}

bool ScalarConverter::isFloat(const std::string& s)
{
    char* end = nullptr;
    errno = 0;
    float f = strtof(s.c_str(), &end);
    return end != s.c_str() && (*end == 'f' || *end == 'F') && end + 1 == s.c_str() + s.size() && errno == 0;
}

bool ScalarConverter::isDouble(const std::string& s)
{
    char* end = nullptr;
    errno = 0;
    strtod(s.c_str(), &end);
    return end != s.c_str() && *end == '\0' && errno == 0;
}

void ScalarConverter::printIntAsChar(int i) {
    std::cout << "char: ";
    if (i < 0 || i > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(i))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
}

void ScalarConverter::printFloatAsChar(float f) {
    std::cout << "char: ";
    if (std::isnan(f) || std::isinf(f) || f < std::numeric_limits<char>::min()
        || f > std::numeric_limits<char>::max() || f - static_cast<int>(f) != 0)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(f)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
}

void ScalarConverter::printDoubleAsChar(double d) {
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<char>::min()
        || d > std::numeric_limits<char>::max() || d - static_cast<int>(d) != 0)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
}

void ScalarConverter::printFloatAsInt(float f) {
    if (std::isnan(f) || std::isinf(f) || f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(f) << std::endl;
}

void ScalarConverter::printDoubleAsInt(double d) {
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;
}

