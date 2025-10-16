#include "Character.hpp"

#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

Character::~Character()
{
	std::cout << "Destructing Character \"" << name << "\"\n";
	for (unsigned int i = 0; i < invSize; ++i)
		delete inventory[i];
}

Character::Character()
	: name("<unnamed>"),
	  inventory()
{
	std::cout << "Default-constructing Character \"" << name << "\"\n";
}

Character::Character(std::string const &name)
	: name(name),
	  inventory()
{
	std::cout << "Constructing Character \"" << name << "\"\n";
}

Character::Character(Character const &other)
	: name(other.name),
	  inventory()
{
	std::cout << "Copy-constructing Character \"" << name << "\"\n";
	for (unsigned int i = 0; i < invSize; ++i)
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
}

Character &Character::operator=(Character const &other)
{
	std::cout << "Copy-assigning Character \"" << other.name << "\" over \"" << name << "\"\n";
	name = other.name;
	for (unsigned int i = 0; i < invSize; ++i)
	{
		delete inventory[i];
		inventory[i] = 0;
	}
	for (unsigned int i = 0; i < invSize; ++i)
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
	return *this;
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	// TODO
	(void)m;
}

void Character::unequip(int idx)
{
	// TODO
	(void)idx;
}

void Character::use(int idx, ICharacter &target)
{
	// TODO
	(void)idx;
	(void)target;
}
