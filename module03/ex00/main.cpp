#include "ClapTrap.hpp"


int main()
{
    ClapTrap claptrap("CL1-2");

    claptrap.attack("Target1");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);
    return 0;
}
