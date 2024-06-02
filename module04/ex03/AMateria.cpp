#include "AMateria.hpp"

AMateria::AMateria():_type("")
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::AMateria(const AMateria& other)
{
    *this = other;
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
}
