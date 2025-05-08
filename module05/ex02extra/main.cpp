#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat a("a", 140);
        Form c("c", 7);

        a.signForm(c);
        std::cout<<c;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}