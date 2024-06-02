#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap named " << this->_name << " is created" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout<< "For ScavTrap named " <<this->_name<<" Destructor called"<<std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->_energyPoints >= 1)
    {
        std::cout<<"ScavTrap named "<<this->_name<<" attacks "<<target<<", causing "
                <<this->_attackDamage<<" points of damage!"<<std::endl;
        this->_energyPoints--;
    }
    else
        std::cout << "ScavTrap named " << this->_name << " has no energy" << std::endl;
}

void ScavTrap::guardGate() const
{
    std::cout << "ScavTrap " << this->_name << " is now in Gatekeeper mode." << std::endl;
}