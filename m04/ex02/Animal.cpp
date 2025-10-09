#include "Animal.hpp"

#include <iostream>

AAnimal::~AAnimal()
{
	std::cout << "Destructing AAnimal\n";
}

AAnimal::AAnimal()
	: type()
{
	std::cout << "Default-constructing AAnimal\n";
}

AAnimal::AAnimal(AAnimal const &other)
	: type(other.type)
{
	std::cout << "Copy-constructing AAnimal\n";
}

AAnimal &AAnimal::operator=(AAnimal const &other)
{
	type = other.type;
	std::cout << "Copy-assigning AAnimal\n";
	return *this;
}

std::string const &AAnimal::getType() const
{
	return type;
}
