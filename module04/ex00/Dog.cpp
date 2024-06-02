#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout<<"Dog constructed"<<std::endl;
}

Dog::~Dog()
{
    std::cout<<"Dog destructed"<<std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}