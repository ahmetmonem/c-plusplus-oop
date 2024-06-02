#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Generic WrongAnimal")
{
    std::cout<<"WrongAnimal constructed"<<std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout<<"WrongAnimal destructed"<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
    std::cout<<"WrongAnimal copy constructor called"<<std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout<<"WrongAnimal copy assignment called"<<std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

std::string    WrongAnimal::getType() const
{
    return this->type;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "Generic WrongAnimal sound" << std::endl;
}