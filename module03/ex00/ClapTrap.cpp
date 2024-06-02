#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name) : _name(name),
                             _hitPoints(10),
                             _energyPoints(10),
                             _attackDamage(0)
{
    std::cout << "ClapTrap named " << this->_name << " is created" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout<< "For ClapTrap named " <<this->_name<<" Destructor called"<<std::endl;
}

ClapTrap::ClapTrap(ClapTrap& other) : _name(other._name),
                         _hitPoints(other._hitPoints),
                         _energyPoints(other._energyPoints),
                         _attackDamage(other._attackDamage)
{
    std::cout<<"Copy constructor called"<<std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap& other)
{
    std::cout<<"Copy assignment called"<<std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_attackDamage = other._attackDamage;
        this->_energyPoints = other._energyPoints;
        this->_hitPoints = other._hitPoints;
    }
    return *this;
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->_energyPoints >= 1)
    {
        std::cout<<"ClapTrap named "<<this->_name<<" attacks "<<target<<", causing "
                <<this->_attackDamage<<" points of damage!"<<std::endl;
        this->_energyPoints--;
    }
    else
        std::cout << "ClapTrap named " << this->_name << " has no energy" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
        if (this->_hitPoints > 0) 
        {
            std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
            this->_hitPoints = (amount >= this->_hitPoints) ? 0 : this->_hitPoints - amount;
        }
        else
            std::cout << "ClapTrap " << this->_name << " has no hit points left and can't take any more damage." << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints >= 1) 
    {
        std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " hit points!" << std::endl;
        this->_hitPoints += amount;
        this->_energyPoints --;
    }
    else 
        std::cout << "ClapTrap " << this->_name << " has insufficient energy points to be repaired." << std::endl;
}
