#include "Point.hpp"

int main(void)
{
    bool    result;
    Point A(0.0f, 0.0f);
    Point B(4.0f, 0.0f);
    Point C(2.0f, 3.0f);
    Point P(2.0f, 1.4f);

    Point inside(2.0f, 1.0f);
    Point outside(6.0f, 4.0f);
    Point onvertex(0.0f, 0.0f);
    Point onedge(3.0f, 0.0f);

    result = bsp(A, B, C, P);
    std::cout<<"random pooint:";
    std::cout << std::boolalpha << result << std::endl;
    result = bsp(A, B, C, inside);
    std::cout<<"inside pooint:";
    std::cout << std::boolalpha << result << std::endl;
    result = bsp(A, B, C, outside);
    std::cout<<"outside pooint:";
    std::cout << std::boolalpha << result << std::endl;
    result = bsp(A, B, C, onvertex);
    std::cout<<"onvertex pooint:";
    std::cout << std::boolalpha << result << std::endl;
    result = bsp(A, B, C, onedge);
    std::cout<<"onedge pooint:";
    std::cout << std::boolalpha << result << std::endl;
    return (0);
}