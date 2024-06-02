#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
                            :AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::srand(std::time(0));
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src):AForm::AForm(src), _target(src._target)
{
    std::srand(std::time(0));
}


RobotomyRequestForm  &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    if (this != &src) {
        AForm::operator=(src);
        _target = src._target;
    }
    return *this;
}

void    RobotomyRequestForm::beExecuted(Bureaucrat const &bureaucrat) const
{
    (void)bureaucrat;
    std::cout << "* Drilling noises *" << std::endl;
    if (std::rand() % 2) {
        std::cout << _target << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "The robotomy on " << _target << " failed." << std::endl;
    }
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &src)
{
    o << "-----------\n " << "Form info: " <<"\nsigned: "<< src.getSign()<<"\nname: "
    << src.getName() << "\nGrade required to sign :" 
    << src.getGradeReqS()<< "\nGrade required to execute "<< src.getGradeReqE()
    << "\n-----------"<<std::endl;
    return o;
}