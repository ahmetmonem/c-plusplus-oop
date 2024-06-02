#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap scavTrap("SC1-2");
    
    scavTrap.attack("Target2");
    scavTrap.takeDamage(30);
    scavTrap.beRepaired(15);
    scavTrap.guardGate();
    return 0;
}
