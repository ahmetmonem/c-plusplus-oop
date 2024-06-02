#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamondTrap("DI1-4");
    DiamondTrap dia("dia");

    diamondTrap.attack("Target4");
    diamondTrap.takeDamage(30);
    diamondTrap.beRepaired(15);
    diamondTrap.whoAmI();
    dia.whoAmI();
    return 0;
}
