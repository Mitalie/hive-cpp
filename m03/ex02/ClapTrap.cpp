#include "ClapTrap.hpp"

#include <iostream>
#include <string>

ClapTrap::ClapTrap()
	: name("<unnamed>"),
	  hitPoints(10),
	  energy(10),
	  attackDamage(0)
{
	std::cout << "Default constructing a ClapTrap\n";
}

ClapTrap::ClapTrap(std::string const &name)
	: name(name),
	  hitPoints(10),
	  energy(10),
	  attackDamage(0)
{
	std::cout << "Constructing ClapTrap " << name << "\n";
}

ClapTrap::ClapTrap(ClapTrap const &other)
	: name(other.name),
	  hitPoints(other.hitPoints),
	  energy(other.energy),
	  attackDamage(other.attackDamage)
{
	std::cout << "Copy-constructing ClapTrap " << name << "\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructing ClapTrap " << name << "\n";
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "Copy-assigning ClapTrap " << other.name << " over " << name << "\n";
	name = other.name;
	hitPoints = other.hitPoints;
	energy = other.energy;
	attackDamage = other.attackDamage;
	return *this;
}

void ClapTrap::attack(std::string const &target)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is dead and cannot attack!\n";
		return;
	}
	if (energy == 0)
	{
		std::cout << "ClapTrap " << name << " doesn't have enough energy to attack!\n";
		return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target
			  << ", causing " << attackDamage << " points of damage.\n";
	energy--;
}

void ClapTrap::takeDamage(unsigned int const amount)
{
	if (amount > hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << "ClapTrap " << name << " takes " << amount
			  << " points of damage and has " << hitPoints << " hit points remaining.\n";
}

void ClapTrap::beRepaired(unsigned int const amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is dead and cannot be repaired!\n";
		return;
	}
	if (energy == 0)
	{
		std::cout << "ClapTrap " << name << " doesn't have enough energy to repair!\n";
		return;
	}
	hitPoints += amount;
	std::cout << "ClapTrap " << name << " is repaired for " << amount
			  << " points and now has " << hitPoints << " hit points.\n";
	energy--;
}
