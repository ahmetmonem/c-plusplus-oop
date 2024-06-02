#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap named " << this->_name << " is created" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout<< "For FragTrap named " <<this->_name<<" Destructor called"<<std::endl;
}

void    FragTrap::highFivesGuys() 
{
    if ( this->_energyPoints <= 0 )
    {
        std::cout << "FragTrap " << this->_name << " is out of energy." << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->_name << " high fives everybody." << std::endl;
    this->_energyPoints -= 1;
}