#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
                            :AForm("ShrubberyCreationForm", 145, 137), _target(target){}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src):AForm::AForm(src), _target(src._target){}


ShrubberyCreationForm  &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    if (this != &src) {
        AForm::operator=(src);
        _target = src._target;
    }
    return *this;
}

void    ShrubberyCreationForm::beExecuted(Bureaucrat const &bureaucrat) const
{
    std::ofstream file;
    file.open((this->_target + "_shrubbery").c_str());
    if (!file)
    {
        std::cerr << "Error: Could not create file " << _target + "_shrubbery" << std::endl;
        return;
    }
    file << "       _-_" << std::endl;
    file << "    /~~   ~~\\" << std::endl;
    file << " /~~         ~~\\" << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  /" << std::endl;
    file << "   ~  \\ //  ~" << std::endl;
    file << "_- -   | | _- _" << std::endl;
    file << "  _ -  | |   -_" << std::endl;
    file << "      // \\" << std::endl;
    file.close();
	std::cout << bureaucrat.getName() << " successfully created a shrubbery" << std::endl;

}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    // std::cout<<this->_target<<" destructed ";
}

std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &src)
{
    o << "-----------\n " << "Form info: " <<"\nsigned: "<< src.getSign()<<"\nname: "
    << src.getName() << "\nGrade required to sign :" 
    << src.getGradeReqS()<< "\nGrade required to execute "<< src.getGradeReqE()
    << "\n-----------"<<std::endl;
    return o;
}