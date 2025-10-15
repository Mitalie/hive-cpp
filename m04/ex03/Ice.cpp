#include "Ice.hpp"

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

Ice::~Ice()
{
	std::cout << "Destructing Ice\n";
}

Ice::Ice()
	: AMateria("ice")
{
	std::cout << "Default-constructing Ice\n";
}

Ice::Ice(Ice const &other)
	: AMateria(other)
{
	std::cout << "Copy-constructing Ice\n";
}

Ice &Ice::operator=(Ice const &other)
{
	AMateria::operator=(other);
	std::cout << "Copy-assigning Ice\n";
	return *this;
}

Ice *Ice::clone() const
{
	std::cout << "Cloning Ice\n";
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
