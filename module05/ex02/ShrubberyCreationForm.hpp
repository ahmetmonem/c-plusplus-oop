#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;
public:
    ShrubberyCreationForm(std::string target = "Default");
    ShrubberyCreationForm(const ShrubberyCreationForm &src);

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

    void	beExecuted(Bureaucrat const &bureaucrat) const;
    ~ShrubberyCreationForm();
};

std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &src);

#endif
