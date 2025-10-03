#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>
#include <string>

ScavTrap::ScavTrap()
	: ClapTrap()
{
	hitPoints = 100;
	energy = 50;
	attackDamage = 20;
	std::cout << "Default constructing a ScavTrap\n";
}

ScavTrap::ScavTrap(std::string const &name)
	: ClapTrap(name)
{
	hitPoints = 100;
	energy = 50;
	attackDamage = 20;
	std::cout << "Constructing ScavTrap " << name << "\n";
}

ScavTrap::ScavTrap(ScavTrap const &other)
	: ClapTrap(other)
{
	std::cout << "Copy-constructing ScavTrap " << name << "\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructing ScavTrap " << name << "\n";
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	std::cout << "Copy-assigning ScavTrap " << other.name << " over " << name << "\n";
	this->ClapTrap::operator=(other);
	return *this;
}

void ScavTrap::attack(std::string const &target)
{
	if (hitPoints == 0)
	{
		std::cout << "ScavTrap " << name << " is dead and cannot attack!\n";
		return;
	}
	if (energy == 0)
	{
		std::cout << "ScavTrap " << name << " doesn't have enough energy to attack!\n";
		return;
	}
	std::cout << "ScavTrap " << name << " punches " << target
			  << ", causing " << attackDamage << " points of damage.\n";
	energy--;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in gatekeeper mode.\n";
}
