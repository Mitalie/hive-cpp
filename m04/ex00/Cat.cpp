#include "Cat.hpp"
#include "Animal.hpp"

#include <iostream>

Cat::~Cat()
{
	std::cout << "Destructing Cat\n";
}

Cat::Cat()
	: Animal()
{
	type = "Cat";
	std::cout << "Default-constructing Cat\n";
}

Cat::Cat(Cat const &other)
	: Animal(other)
{
	std::cout << "Copy-constructing Cat\n";
}

Cat &Cat::operator=(Cat const &other)
{
	Animal::operator=(other);
	std::cout << "Copy-assigning Cat\n";
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "<the cat meows>\n";
}
