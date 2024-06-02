#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;
public:
    PresidentialPardonForm(std::string target = "Default");
    PresidentialPardonForm(const PresidentialPardonForm &src);

    PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

    void	beExecuted(Bureaucrat const &bureaucrat) const;
    ~PresidentialPardonForm();
};

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &src);

#endif
