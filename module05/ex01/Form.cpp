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

Form::Form(std::string name, int gradeReqSign, int gradeReqExc)
                                    : _name(name), _gradeReqSign(gradeReqSign),
                                    _gradeReqExc(gradeReqExc), _isSigned(false)
{
    if (gradeReqSign > 150 || gradeReqExc > 150)
        throw GradeTooLowException();
    if (gradeReqSign < 1 || gradeReqExc < 1)
        throw GradeTooHighException();
    //std::cout << "Form class constructed"<<std::endl;
}

Form::Form(const Form &src) : _name(src._name), _gradeReqSign(src._gradeReqSign),
                            _gradeReqExc(src._gradeReqExc)
{
    *this = src;
}

Form    &Form::operator=(const Form &src)
{
    if (this == &src)
		return *this;
    this->_isSigned = src._isSigned;
    return *this;
}

std::string Form::getName() const
{
    return this->_name;
}
bool    Form::getSign() const
{
    return this->_isSigned;
}

int Form::getGradeReqS() const
{
    return this->_gradeReqSign;
}

int Form::getGradeReqE() const
{
    return this->_gradeReqExc;
}

void    Form::beSigned(const Bureaucrat &a)
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

Form::~Form()
{
    //std::cout<<"Form destructed"<<std::endl;
}

std::ostream &operator<<(std::ostream &o, const Form &src)
{
    o << "-----------\n " << "Form info: " <<"\nsigned: "<< src.getSign()<<"\nname: "
    << src.getName() << "\nGrade required to sign :" 
    << src.getGradeReqS()<< "\nGrade required to execute "<< src.getGradeReqE()
    << "\n-----------"<<std::endl;
    return o;
}
