#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout<<"Cat constructed"<<std::endl;
}

Cat::~Cat()
{
    std::cout<<"Cat destructed"<<std::endl;
}

void Cat::makeSound() const 
{
    std::cout << "Meow! Meow!" << std::endl;
}