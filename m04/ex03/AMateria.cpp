#include "AMateria.hpp"

#include <iostream>
#include <string>

AMateria::~AMateria()
{
	std::cout << "Destructing AMateria of type \"" << type << "\"\n";
}

std::string const &AMateria::getType() const
{
	return type;
}

AMateria::AMateria(std::string const &type)
	: type(type)
{
	std::cout << "Constructing AMateria of type \"" << type << "\"\n";
}

AMateria::AMateria(AMateria const &other)
	: type(other.type)
{
	std::cout << "Copy-constructing AMateria of type \"" << type << "\"\n";
}
