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
    const int           _gradeReqSign;
    const int           _gradeReqExc;
public:
    Form(std::string name = "default", int gradeReqSign = 150, int gradeReqExc = 149);
    Form(const Form &src);

    Form    &operator=(const Form &src);

    std::string getName() const;
    bool        getSign() const;
    int         getGradeReqS() const;
    int         getGradeReqE() const;
    class       GradeTooHighException;
    class       GradeTooLowException;
    void        beSigned(const Bureaucrat &a);

    ~Form();
};

std::ostream &operator<<(std::ostream &o, const Form &src);

#endif