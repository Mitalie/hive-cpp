#pragma once

#include <string>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
	~Dog();
	Dog();
	Dog(Dog const &other);
	Dog &operator=(Dog const &other);

	void makeSound() const;

	void setIdea(unsigned int index, std::string idea);
	std::string getIdea(unsigned int index);

private:
	Brain *brain;
};
