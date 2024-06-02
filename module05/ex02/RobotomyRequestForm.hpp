#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;
public:
    RobotomyRequestForm(std::string target = "Default");
    RobotomyRequestForm(const RobotomyRequestForm &src);

    RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

    void	beExecuted(Bureaucrat const &bureaucrat) const;
    ~RobotomyRequestForm();
};

std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &src);

#endif
