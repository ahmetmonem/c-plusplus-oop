#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string   _name;
    bool                _isSigned;
    const int           _gradeReqSign;
    const int           _gradeReqExc;
public:
    AForm(std::string name = "default", int gradeReqSign = 150, int gradeReqExc = 149);
    AForm(const AForm &src);

    AForm    &operator=(const AForm &src);

    std::string getName() const;
    bool        getSign() const;
    int         getGradeReqS() const;
    int         getGradeReqE() const;
    class       GradeTooHighException;
    class       GradeTooLowException;
    class       FormNotSignedException;
    void        beSigned(const Bureaucrat &a);

    void            execute(Bureaucrat const & executor) const;
    virtual void	beExecuted(Bureaucrat const &bureaucrat) const = 0;
    virtual         ~AForm();
};

std::ostream &operator<<(std::ostream &o, const AForm &src);

#endif