#include "Cure.hpp"

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::~Cure()
{
	std::cout << "Destructing Cure\n";
}

Cure::Cure()
	: AMateria("cure")
{
	std::cout << "Default-constructing Cure\n";
}

Cure::Cure(Cure const &other)
	: AMateria(other)
{
	std::cout << "Copy-constructing Cure\n";
}

Cure &Cure::operator=(Cure const &other)
{
	AMateria::operator=(other);
	std::cout << "Copy-assigning Cure\n";
	return *this;
}

Cure *Cure::clone() const
{
	std::cout << "Cloning Cure\n";
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
