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

class   AForm::FormNotSignedException: public std::exception
{
public:
    virtual const char* what() const throw()////
    {
        return "Form not signed";
    }
};

AForm::AForm(std::string name, int gradeReqSign, int gradeReqExc)
                                    : _name(name), _gradeReqSign(gradeReqSign),
                                    _gradeReqExc(gradeReqExc), _isSigned(false)
{
    if (gradeReqSign > 150 || gradeReqExc > 150)
        throw GradeTooLowException();
    if (gradeReqSign < 1 || gradeReqExc < 1)
        throw GradeTooHighException();
    //std::cout << "AForm class constructed"<<std::endl;
}

AForm::AForm(const AForm &src) : _name(src._name), _gradeReqSign(src._gradeReqSign),
                            _gradeReqExc(src._gradeReqExc)
{
    *this = src;
}

AForm    &AForm::operator=(const AForm &src)
{
    if (this == &src)
		return *this;
    this->_isSigned = src._isSigned;
    return *this;
}

std::string AForm::getName() const
{
    return this->_name;
}
bool    AForm::getSign() const
{
    return this->_isSigned;
}

int AForm::getGradeReqS() const
{
    return this->_gradeReqSign;
}

int AForm::getGradeReqE() const
{
    return this->_gradeReqExc;
}

void    AForm::beSigned(const Bureaucrat &a)
{
    if (a.getGrade() <= this->_gradeReqSign)
    {
        this->_isSigned = true;
    }
    else
    {
        throw GradeTooLowException();
    }
}

void    AForm::execute(Bureaucrat const & executor) const
{
    if (!this->_isSigned)
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->_gradeReqExc)
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << executor.getName() << " executes Form: " << this->_name << std::endl;
        this->beExecuted(executor);
    }
}

AForm::~AForm()
{
    // std::cout<<"AForm destructed"<<std::endl;
}

std::ostream &operator<<(std::ostream &o, const AForm &src)
{
    o << "-----------\n " << "Form info: " <<"\nsigned: "<< src.getSign()<<"\nname: "
    << src.getName() << "\nGrade required to sign :" 
    << src.getGradeReqS()<< "\nGrade required to execute "<< src.getGradeReqE()
    << "\n-----------"<<std::endl;
    return o;
}
