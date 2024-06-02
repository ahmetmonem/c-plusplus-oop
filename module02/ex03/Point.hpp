#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
private:
    const Fixed _x;
    const Fixed _y;
public:
    Point();
    Point(const float x_v, const float y_v);
    Point(const Point& other);
    Point& operator=(const Point& other);
    ~Point();

    Fixed           get_x_value() const;
    Fixed           get_y_value() const;
    static Fixed    fixed_abs(Fixed i);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif