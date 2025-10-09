#pragma once

#include <string>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
public:
	~Cat();
	Cat();
	Cat(Cat const &other);
	Cat &operator=(Cat const &other);

	void makeSound() const;

	void setIdea(unsigned int index, std::string idea);
	std::string getIdea(unsigned int index);

private:
	Brain *brain;
};
