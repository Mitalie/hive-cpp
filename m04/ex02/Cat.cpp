#include "Cat.hpp"

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Brain.hpp"

Cat::~Cat()
{
	delete brain;
	std::cout << "Destructing Cat\n";
}

Cat::Cat()
	: AAnimal(),
	  brain(new Brain())
{
	type = "Cat";
	std::cout << "Default-constructing Cat\n";
}

Cat::Cat(Cat const &other)
	: AAnimal(other),
	  brain(new Brain(*other.brain))
{
	std::cout << "Copy-constructing Cat\n";
}

Cat &Cat::operator=(Cat const &other)
{
	AAnimal::operator=(other);
	Brain *copy = new Brain(*other.brain);
	delete brain;
	brain = copy;
	std::cout << "Copy-assigning Cat\n";
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "<the cat meows>\n";
}

void Cat::setIdea(unsigned int index, std::string idea)
{
	brain->setIdea(index, idea);
}

std::string Cat::getIdea(unsigned int index)
{
	return brain->getIdea(index);
}
