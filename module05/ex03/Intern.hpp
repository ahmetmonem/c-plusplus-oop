#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
    Intern();
    Intern(Intern const &src);
    Intern &operator=(Intern const &src);

	AForm *makeForm(const std::string form, const std::string target);
    
    ~Intern();
};

#endif