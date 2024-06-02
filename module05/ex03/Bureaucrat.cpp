#include "Bureaucrat.hpp"

class   Bureaucrat::GradeTooHighException: public std::exception
{
public:
    virtual const char* what() const throw()////
    {
        return "Grade is too high";
    }
};

class   Bureaucrat::GradeTooLowException: public std::exception
{
public:
    virtual const char* what() const throw()////
    {
        return "Grade is too low";
    }
};

Bureaucrat::Bureaucrat(std::string name, int grade):_grade(grade), _name(name)
{
    // std::cout<<_name<<" Bureaucrat constructed"<<std::endl;
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src.getName())
{
    *this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this == &src)
		return *this;
	this->_grade = src.getGrade();
	return *this;
}

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}


void    Bureaucrat::incrementGrade()
{
    if (_grade > 1)
        _grade--;
    else
        throw GradeTooHighException();
}

void    Bureaucrat::decrementGrade()
{
    if (_grade < 150)
        _grade++;
    else
        throw GradeTooLowException();
}

void    Bureaucrat::signForm(AForm &a) const
{
	try
	{
		a.beSigned(*this);
		std::cout << this->_name << " signed " << a.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn’t sign " << a.getName() << " because: " << e.what() << std::endl;
	}
}

void    Bureaucrat::executeForm(AForm const &a) const
{
	try
	{
		a.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " cannot execute " << a.getName() << " because: " << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
    // std::cout<<_name<<" Bureaucrat destructed"<<std::endl;
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &a) // Use const Bureaucrat& reference
{
	o << "Bureaucrat " << a.getName() << ":\tgrade: " << a.getGrade() << std::endl;
	return (o);
}


