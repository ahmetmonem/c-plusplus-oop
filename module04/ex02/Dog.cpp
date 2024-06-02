#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout<<"Dog constructed"<<std::endl;
    this->_brain = new Brain();
}

Dog::Dog(const Dog& other) : _brain(new Brain(*(other._brain)))
{
    std::cout<<"Cat copy constructor called"<<std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout<<"Dog copy assignment called"<<std::endl;
    if (this != &other)
    {
        this->type = other.type;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete this->_brain;
    std::cout<<"Dog destructed"<<std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}