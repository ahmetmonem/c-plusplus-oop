#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout<<"Cat constructed"<<std::endl;
    this->_brain = new Brain();
}

Cat::Cat(const Cat& other) : _brain(new Brain(*(other._brain)))
{
    std::cout<<"Cat copy constructor called"<<std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout<<"Cat copy assignment called"<<std::endl;
    if (this != &other)
    {
        this->type = other.type;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

Cat::~Cat()
{
    delete this->_brain;
    std::cout<<"Cat destructed"<<std::endl;
}

void Cat::makeSound() const 
{
    std::cout << "Meow! Meow!" << std::endl;
}