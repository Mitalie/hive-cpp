#include "Dog.hpp"
#include "Animal.hpp"

#include <iostream>

Dog::~Dog()
{
	std::cout << "Destructing Dog\n";
}

Dog::Dog()
	: Animal()
{
	type = "Dog";
	std::cout << "Default-constructing Dog\n";
}

Dog::Dog(Dog const &other)
	: Animal(other)
{
	std::cout << "Copy-constructing Dog\n";
}

Dog &Dog::operator=(Dog const &other)
{
	Animal::operator=(other);
	std::cout << "Copy-assigning Dog\n";
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "<the dog barks>\n";
}
