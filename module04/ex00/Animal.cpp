#include "Animal.hpp"

Animal::Animal() : type("Generic Animal")
{
    std::cout<<"Animal constructed"<<std::endl;
}

Animal::~Animal()
{
    std::cout<<"Animal destructed"<<std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout<<"Animal copy constructor called"<<std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout<<"Animal copy assignment called"<<std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

std::string    Animal::getType() const
{
    return this->type;
}

void    Animal::makeSound() const
{
    std::cout << "Generic animal sound" << std::endl;
}