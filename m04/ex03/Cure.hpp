#pragma once

#include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria
{
public:
	~Cure();
	Cure();
	Cure(Cure const &other);
	Cure &operator=(Cure const &other);

	Cure *clone() const;
	void use(ICharacter &target);
};
