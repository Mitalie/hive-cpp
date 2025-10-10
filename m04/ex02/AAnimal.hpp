#pragma once

#include <string>

class AAnimal
{
public:
	virtual ~AAnimal();
	AAnimal();
	AAnimal(AAnimal const &other);
	AAnimal &operator=(AAnimal const &other);

	std::string const &getType() const;
	virtual void makeSound() const = 0;

protected:
	std::string type;
};
