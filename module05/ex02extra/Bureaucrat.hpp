#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
    std::string const   _name;
    int                 _grade;
public:
    Bureaucrat(std::string name = "default", int grade = 150);
    Bureaucrat(const Bureaucrat &src);

    Bureaucrat      &operator=(const Bureaucrat &src);

    std::string getName() const;
    int         getGrade() const;
    class       GradeTooHighException;
    class       GradeTooLowException;
    void        incrementGrade();
    void        decrementGrade();

    void        signForm(AForm& f);

   ~Bureaucrat();
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &a);

#endif
