#include "Character.hpp"

Character::Character(std::string const & name) : _name(name)
{
    for (int i = 0; i < 4; i++)
    {
        this->_slots[i] = NULL;
    }
    // std::cout << "Character " << this->_name << " created" << std::endl;
}

Character::Character(Character const & other)
{
    for (int i = 0; i < 4; i++)
        this->_slots[i] = other._slots[i];
    *this = other;
    std::cout << "Copy constructor called." << std::endl;
}

Character& Character::operator=( Character const & other )
{
    if (this != &other)
    {
        this->_name = other._name;
        for (int i = 0; i < 4; i++)
            this->_slots[i] = other._slots[i];
    }
    return *this;
}

Character::~Character()
{
    // std::cout << "Character " << this->_name << " destroyed" << std::endl;
    for (int i = 0; i < 4; i++)
        if (this->_slots[i])
            delete this->_slots[i];
}

void    Character::equip( AMateria* m )
{
    for (int i = 0; i < 4; i++)
        if (this->_slots[i] == NULL)
        {
            this->_slots[i] = m;
            // std::cout << "Character " << this->_name << " equipped with " << m->getType() << std::endl;
            return ;
        }
    std::cout << "Character " << this->_name << " can't equip " << m->getType() << std::endl;
}

void    Character::unequip( int idx )
{
    if (this->_slots[idx])
    {
        delete this->_slots[idx];
        this->_slots[idx] = NULL;
        // std::cout << "Character " << this->_name << " unequipped" << std::endl;
    }
    else
        std::cout << "Character " << this->_name << " can't unequip" << std::endl;
}

void    Character::use( int idx, ICharacter& target ) {
    if (this->_slots[idx])
    {
        this->_slots[idx]->use(target);
        // std::cout << "Character " << this->_name << " uses " << this->_slots[idx]->getType() << std::endl;
    }
    else
        std::cout << "Character " << this->_name << " can't use" << std::endl;
}

std::string const& Character::getName() const {
    return this->_name;
}