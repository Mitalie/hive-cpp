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
	this->ClapTrap::operator=(other);
	return *this;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in gatekeeper mode.\n";
}
