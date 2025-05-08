#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"


class Bureaucrat;

class Form
{
private:
    const std::string   _name;
    bool                _isSigned;
    const int           _gradeToSign;
    const int           _gradeToExec;
public:
    Form(std::string name = "default", int gradeToSign = 150, int gradeToExec = 150);
    ~Form();

    std::string getName() const;
    bool        getIsSigned() const;
    int         getGradeToSign() const;
    int         getGradeToExec() const;

    void        beSigned(const Bureaucrat& b);

    
    class GradeTooLowException;
    class GradeTooHighException;

};

std::ostream &operator<<(std::ostream& out,const Form& form);

#endif