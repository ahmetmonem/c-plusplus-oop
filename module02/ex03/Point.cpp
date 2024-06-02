#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
    //std::cout<<"Default constructor called"<<std::endl;
}

Point::Point(const float x_v, const float y_v) : _x(x_v) , _y(y_v)
{
    //std::cout<<"initialize constructor called"<<std::endl;
}

Point::Point(const Point& other) : _x(other._x), _y(other._y)
{
    //std::cout<<"Copy constructor called"<<std::endl;
}

Point& Point::operator=(const Point& other)
{
    //std::cout<<"Copy assignment operator called"<<std::endl;
    if (this != &other)
    {
        (Fixed) this->_x = other._x;
        (Fixed) this->_y = other._y;
    }
    return (*this);
}

Point::~Point()
{
    //std::cout<<"Destructor called"<<std::endl;
}

Fixed   Point::get_x_value() const
{
    return this->_x;
}

Fixed   Point::get_y_value() const
{
    return this->_y;
}

Fixed   Point::fixed_abs(Fixed i)
{
    if (i.toFloat() < 0)
        return Fixed(i.toFloat()) * Fixed(-1);
    else
        return i;
}