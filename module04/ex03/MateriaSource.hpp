#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria*       materias[4];

    public:
        MateriaSource();
        ~MateriaSource();

        MateriaSource( MateriaSource const & other);
        MateriaSource&  operator=( MateriaSource const & other);

        AMateria*       createMateria( std::string const & type );
        void            learnMateria( AMateria* m );
};


#endif