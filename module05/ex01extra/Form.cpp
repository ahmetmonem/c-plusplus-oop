#include "Form.hpp"

class   Form::GradeTooHighException: public std::exception
{
public:
    virtual const char* what() const throw()////
    {
        return "Grade is too high";
    }
};

class   Form::GradeTooLowException: public std::exception
{
public:
    virtual const char* what() const throw()////
    {
        return "Grade is too low";
    }
};

Form::Form(std::string name, int gradeToSign, int gradeToExec):_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec),_isSigned(false)
{
    std::cout<<"constructor called"<<std::endl;
}

std::string Form::getName() const
{
    return this->_name;
}

bool        Form::getIsSigned() const
{
    return this->_isSigned;
}

int         Form::getGradeToSign() const
{
    return this->_gradeToSign;
}

int         Form::getGradeToExec() const
{
    return this->_gradeToExec;
}


void    Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= this->_gradeToSign)
        this->_isSigned = true;
    else
        throw GradeTooLowException();
}


std::ostream &operator<<(std::ostream& out,const Form& form)
{
out << "Form name: " << form.getName()
    << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
    << ", Grade to Sign: " << form.getGradeToSign()
    << ", Grade to Execute: " << form.getGradeToExec()<< std::endl;
    return (out);
}

Form::~Form()
{
    std::cout<<"destructor called"<<std::endl;
}