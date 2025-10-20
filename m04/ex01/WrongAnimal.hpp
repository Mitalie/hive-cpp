#pragma once

#include <string>

class WrongAnimal
{
public:
	~WrongAnimal();
	WrongAnimal();
	WrongAnimal(WrongAnimal const &other);
	WrongAnimal &operator=(WrongAnimal const &other);

	std::string const &getType() const;
	void makeSound() const;

protected:
	std::string type;
};
