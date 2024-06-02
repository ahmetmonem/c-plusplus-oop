#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
                            :AForm("PresidentialPardonForm", 25, 5), _target(target){}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src):AForm::AForm(src), _target(src._target){}


PresidentialPardonForm  &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    if (this != &src) {
        AForm::operator=(src);
        _target = src._target;
    }
    return *this;
}

void    PresidentialPardonForm::beExecuted(Bureaucrat const &bureaucrat) const
{
    (void)bureaucrat;
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &src)
{
    o << "-----------\n " << "Form info: " <<"\nsigned: "<< src.getSign()<<"\nname: "
    << src.getName() << "\nGrade required to sign :" 
    << src.getGradeReqS()<< "\nGrade required to execute "<< src.getGradeReqE()
    << "\n-----------"<<std::endl;
    return o;
}