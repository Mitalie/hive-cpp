#pragma once

#include <string>

class Animal
{
public:
	virtual ~Animal();
	Animal();
	Animal(Animal const &other);
	Animal &operator=(Animal const &other);

	std::string const &getType() const;
	virtual void makeSound() const = 0;

protected:
	std::string type;
};
