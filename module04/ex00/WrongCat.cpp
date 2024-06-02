#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout<<"WrongCat constructed"<<std::endl;
}

WrongCat::~WrongCat()
{
    std::cout<<"WrongCat destructed"<<std::endl;
}

void WrongCat::makeSound() const 
{
    std::cout << "Meow! Meow!" << std::endl;
}