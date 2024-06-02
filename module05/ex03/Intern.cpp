#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(Intern const &src)
{
    *this = src;
}

Intern  &Intern::operator=(Intern const &src)
{
    return *this;
}

AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(const std::string form_to_create, const std::string target_for_form)
{
	AForm *(*all_forms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (form_to_create == forms[i])
		{
			std::cout << "Intern creates " << form_to_create<< std::endl;
			return (all_forms[i](target_for_form));
		}
	}
	std::cout << "Intern can not create a form called " << form_to_create << std::endl;
	return (NULL);
}

Intern::~Intern(){}

