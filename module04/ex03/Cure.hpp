#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure(Cure const & other);
    Cure& operator=( Cure const & other);
    ~Cure();

    AMateria*   clone() const;
    void        use(ICharacter& target);
};

#endif