#pragma once

#include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria
{
public:
	~Ice();
	Ice();
	Ice(Ice const &other);
	Ice &operator=(Ice const &other);

	Ice *clone() const;
	void use(ICharacter &target);
};
