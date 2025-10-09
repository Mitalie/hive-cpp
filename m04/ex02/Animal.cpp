#include "Animal.hpp"

#include <iostream>

Animal::~Animal()
{
	std::cout << "Destructing Animal\n";
}

Animal::Animal()
	: type()
{
	std::cout << "Default-constructing Animal\n";
}

Animal::Animal(Animal const &other)
	: type(other.type)
{
	std::cout << "Copy-constructing Animal\n";
}

Animal &Animal::operator=(Animal const &other)
{
	type = other.type;
	std::cout << "Copy-assigning Animal\n";
	return *this;
}

std::string const &Animal::getType() const
{
	return type;
}
