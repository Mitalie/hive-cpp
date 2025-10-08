#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
public:
	~Cat();
	Cat();
	Cat(Cat const &other);
	Cat &operator=(Cat const &other);

	void makeSound() const;
};
