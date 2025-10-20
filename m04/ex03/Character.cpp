#include "Character.hpp"

#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "MateriaDiscard.hpp"

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
	std::cout << "Character \"" << name << "\" equips materia of type \"" << m->getType() << "\"...";
	for (unsigned int i = 0; i < invSize; ++i)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			std::cout << " selected inventory slot " << i << "\n";
			return;
		}
	}
	std::cout << " discarding it as inventory is full\n";
	MateriaDiscard::discard(m);
}

void Character::unequip(int idx)
{
	std::cout << "Character \"" << name << "\" unequips materia in inventory slot " << idx << "...";
	if (idx >= 0 && idx < invSize && inventory[idx])
	{
		AMateria *m = inventory[idx];
		inventory[idx] = 0;
		std::cout << " discarding materia of type \"" << m->getType() << "\"\n";
		MateriaDiscard::discard(m);
	}
	else if (idx >= 0 && idx < invSize)
		std::cout << " slot is empty\n";
	else
		std::cout << " slot is invalid\n";
}

void Character::use(int idx, ICharacter &target)
{
	std::cout << "Character \"" << name << "\" uses materia in inventory slot " << idx << "...";
	if (idx >= 0 && idx < invSize && inventory[idx])
	{
		std::cout << "\n";
		inventory[idx]->use(target);
	}
	else if (idx >= 0 && idx < invSize)
		std::cout << " slot is empty\n";
	else
		std::cout << " slot is invalid\n";
}
