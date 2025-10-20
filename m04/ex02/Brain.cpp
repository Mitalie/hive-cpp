#include "Brain.hpp"

#include <iostream>

Brain::~Brain()
{
	std::cout << "Destructing Brain\n";
}

Brain::Brain()
	: ideas()
{
	std::cout << "Default-constructing Brain\n";
}

Brain::Brain(Brain const &other)
	: ideas()
{
	for (unsigned int i = 0; i < capacity; ++i)
		ideas[i] = other.ideas[i];
	std::cout << "Copy-constructing Brain\n";
}

Brain &Brain::operator=(Brain const &other)
{
	for (unsigned int i = 0; i < capacity; ++i)
		ideas[i] = other.ideas[i];
	std::cout << "Copy-assigning Brain\n";
	return *this;
}

void Brain::setIdea(unsigned int index, std::string idea)
{
	if (index >= capacity)
		return;
	ideas[index] = idea;
}

std::string Brain::getIdea(unsigned int index)
{
	if (index >= capacity)
		return "";
	return ideas[index];
}
