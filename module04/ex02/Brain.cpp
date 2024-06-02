#include "Brain.hpp"

Brain::Brain()
{
    std::cout<<"Brain constructed"<<std::endl;
}

Brain::~Brain()
{
    std::cout<<"Brain destructed"<<std::endl;
}

Brain::Brain(const Brain& other)
{
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        std::copy(other.ideas, other.ideas + 100, this->ideas);
    }
    return *this;
}