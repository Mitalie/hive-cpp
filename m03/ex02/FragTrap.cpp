#include "FragTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>
#include <string>

FragTrap::FragTrap()
	: ClapTrap()
{
	hitPoints = 100;
	energy = 100;
	attackDamage = 30;
	std::cout << "Default constructing a FragTrap\n";
}

FragTrap::FragTrap(std::string const &name)
	: ClapTrap(name)
{
	hitPoints = 100;
	energy = 100;
	attackDamage = 30;
	std::cout << "Constructing FragTrap " << name << "\n";
}

FragTrap::FragTrap(FragTrap const &other)
	: ClapTrap(other)
{
	std::cout << "Copy-constructing FragTrap " << name << "\n";
}

FragTrap::~FragTrap()
{
	std::cout << "Destructing FragTrap " << name << "\n";
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
	std::cout << "Copy-assigning FragTrap " << other.name << " over " << name << "\n";
	this->ClapTrap::operator=(other);
	return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout << "Up high! FragTrap " << name << " requests a high five.\n";
}
