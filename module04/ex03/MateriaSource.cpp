#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        if (materias[i])
            delete materias[i];
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
    *this = other;
}

MateriaSource& MateriaSource::operator=( MateriaSource const & other )
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
            materias[i] = other.materias[i];
    }
    return *this;
}

void    MateriaSource::learnMateria( AMateria* m )
{
    for (int i = 0; i < 4; i++)
        if (materias[i] == NULL)
        {
            materias[i] = m;
            return ;
        }
}

AMateria*   MateriaSource::createMateria( std::string const& type )
{
    for ( int i = 0; i < 4; i++ )
        if ( materias[i] && materias[i]->getType() == type )
            return materias[i]->clone();
    return NULL;
}