#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructing WrongAnimal\n";
}

WrongAnimal::WrongAnimal()
	: type()
{
	std::cout << "Default-constructing WrongAnimal\n";
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
	: type(other.type)
{
	std::cout << "Copy-constructing WrongAnimal\n";
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
	type = other.type;
	std::cout << "Copy-assigning WrongAnimal\n";
	return *this;
}

std::string const &WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "<the animal makes strange sounds>\n";
}
