#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap FragTrap("FR1-3");
    
    FragTrap.attack("Target3");
    FragTrap.takeDamage(30);
    FragTrap.beRepaired(15);
    FragTrap.highFivesGuys();
    return 0;
}
