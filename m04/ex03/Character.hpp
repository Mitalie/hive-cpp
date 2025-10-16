#pragma once

#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	~Character();
	Character();
	Character(std::string const &name);
	Character(Character const &other);
	Character &operator=(Character const &other);

	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

private:
	std::string name;
	static const int invSize = 4;
	AMateria *inventory[invSize];
};
