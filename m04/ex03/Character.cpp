#include "Character.hpp"

#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

Character::~Character()
{
	std::cout << "Destructing Character \"" << name << "\"\n";
}

Character::Character()
	: name("<unnamed>")
{
	std::cout << "Default-constructing Character \"" << name << "\"\n";
}

Character::Character(std::string const &name)
	: name(name)
{
	std::cout << "Constructing Character \"" << name << "\"\n";
}

Character::Character(Character const &other)
	: name(other.name)
{
	std::cout << "Copy-constructing Character \"" << name << "\"\n";
}

Character &Character::operator=(Character const &other)
{
	std::cout << "Copy-assigning Character \"" << other.name << "\" over \"" << name << "\"\n";
	name = other.name;
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
