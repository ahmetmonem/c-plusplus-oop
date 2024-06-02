#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat a("a", 150);
        Form b("y", 10);
        
        std::cout << b;
        a.incrementGrade();
        a.signForm(b);
        std::cout<<a.getGrade()<<std::endl;
        std::cout<<b.getSign()<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}