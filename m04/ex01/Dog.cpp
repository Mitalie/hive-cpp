#include "Dog.hpp"

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Brain.hpp"

Dog::~Dog()
{
	delete brain;
	std::cout << "Destructing Dog\n";
}

Dog::Dog()
	: Animal(),
	  brain(new Brain())
{
	type = "Dog";
	std::cout << "Default-constructing Dog\n";
}

Dog::Dog(Dog const &other)
	: Animal(other),
	  brain(new Brain(*other.brain))
{
	std::cout << "Copy-constructing Dog\n";
}

Dog &Dog::operator=(Dog const &other)
{
	Animal::operator=(other);
	Brain *copy = new Brain(*other.brain);
	delete brain;
	brain = copy;
	std::cout << "Copy-assigning Dog\n";
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "<the dog barks>\n";
}

void Dog::setIdea(unsigned int index, std::string idea)
{
	brain->setIdea(index, idea);
}

std::string Dog::getIdea(unsigned int index)
{
	return brain->getIdea(index);
}
