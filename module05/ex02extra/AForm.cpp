#include "AForm.hpp"

class   AForm::GradeTooHighException: public std::exception
{
public:
    virtual const char* what() const throw()////
    {
        return "Grade is too high";
    }
};

class   AForm::GradeTooLowException: public std::exception
{
public:
    virtual const char* what() const throw()////
    {
        return "Grade is too low";
    }
};

AForm::AForm(std::string name, int gradeToSign, int gradeToExec):_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec),_isSigned(false)
{
    std::cout<<"constructor called"<<std::endl;
}

std::string AForm::getName() const
{
    return this->_name;
}

bool        AForm::getIsSigned() const
{
    return this->_isSigned;
}

int         AForm::getGradeToSign() const
{
    return this->_gradeToSign;
}

int         AForm::getGradeToExec() const
{
    return this->_gradeToExec;
}


void    AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= this->_gradeToSign)
        this->_isSigned = true;
    else
        throw GradeTooLowException();
}


std::ostream &operator<<(std::ostream& out,const AForm& form)
{
out << "Form name: " << form.getName()
    << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
    << ", Grade to Sign: " << form.getGradeToSign()
    << ", Grade to Execute: " << form.getGradeToExec()<< std::endl;
    return (out);
}

AForm::~AForm()
{
    std::cout<<"destructor called"<<std::endl;
}