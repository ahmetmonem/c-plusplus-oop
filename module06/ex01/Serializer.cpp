#include "Serializer.hpp"


Data::Data(std::string i, size_t f, Data *s)
        : name(i), age(f), next(s) {}

Serializer::Serializer()
{
	std::cout << "Serializer Default Constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
	//std::cout << "Serializer Copy Constructor called" << std::endl;
	*this = src;
}

Serializer::~Serializer()
{
	//std::cout << "Serializer Deconstructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &src)
{
	//std::cout << "Serializer Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
