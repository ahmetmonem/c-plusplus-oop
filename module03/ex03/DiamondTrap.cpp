#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) :ClapTrap(name), FragTrap(name), ScavTrap(name)
{
    this->_name = name;
    this->ClapTrap::_name = name + "_clap_name";
    this->FragTrap::_hitPoints = 100;
    this->ScavTrap::_energyPoints = 50;
    this->FragTrap::_attackDamage = 30;
    std::cout<< "DiamondTrap named "<<this->_name<<" is created"<<std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout<<"DiamondTrap named "<<this->_name<<" Destructor called"<<std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout<<"The DiamondTrap name "<<this->_name<<" The ClapTrap name "<<this->ClapTrap::_name<<std::endl;
}