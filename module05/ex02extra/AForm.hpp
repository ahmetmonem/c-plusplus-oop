#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"


class Bureaucrat;

class AForm
{
private:
    const std::string   _name;
    bool                _isSigned;
    const int           _gradeToSign;
    const int           _gradeToExec;
public:
    AForm(std::string name = "default", int gradeToSign = 150, int gradeToExec = 150);
    ~AForm();

    std::string getName() const;
    bool        getIsSigned() const;
    int         getGradeToSign() const;
    int         getGradeToExec() const;

    void        beSigned(const Bureaucrat& b);

    
    class GradeTooLowException;
    class GradeTooHighException;

};

std::ostream &operator<<(std::ostream& out,const AForm& form);

#endif