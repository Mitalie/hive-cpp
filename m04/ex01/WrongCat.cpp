#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

#include <iostream>

WrongCat::~WrongCat()
{
	std::cout << "Destructing WrongCat\n";
}

WrongCat::WrongCat()
	: WrongAnimal()
{
	type = "WrongCat";
	std::cout << "Default-constructing WrongCat\n";
}

WrongCat::WrongCat(WrongCat const &other)
	: WrongAnimal(other)
{
	std::cout << "Copy-constructing WrongCat\n";
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{
	WrongAnimal::operator=(other);
	std::cout << "Copy-assigning WrongCat\n";
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "<the cat meows>\n";
}
