#include "Point.hpp"

Fixed get_the_area( Point const a, Point const b, Point const c)
{
    return Point::fixed_abs((a.get_x_value() * (b.get_y_value() - c.get_y_value()) +
            b.get_x_value() * (c.get_y_value() - a.get_y_value()) +
            c.get_x_value() * (a.get_y_value() - b.get_y_value())) / Fixed(2.0f));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed triangleArea = get_the_area(a, b, c);
    Fixed subArea1 = get_the_area(a, b, point);
    Fixed subArea2 = get_the_area(a, point, c);
    Fixed subArea3 = get_the_area(point, b, c);

    if (subArea1 == Fixed(0.0f) || subArea2 == Fixed(0.0f) || subArea3 == Fixed(0.0f))
    {
        return false;
    }
    else if (triangleArea - (subArea1 + subArea2 + subArea3) == Fixed(0.0f))
    {
        return true;
    }
    else
    {
        return false;
    }
}