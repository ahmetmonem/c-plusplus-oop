#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a;
        Bureaucrat b("y", 149);
        
        std::cout << b;
        a.incrementGrade();
        b.decrementGrade();
        std::cout<<a.getGrade()<<std::endl;
        std::cout<<b.getGrade()<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}