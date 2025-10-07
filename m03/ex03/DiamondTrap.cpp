#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>
#include <string>

DiamondTrap::DiamondTrap()
	: ClapTrap("<unnamed>_clap_name"), // default constructor wouldn't get the suffix right
	  FragTrap(),
	  ScavTrap(),
	  name("<unnamed>")
{
	hitPoints = FragTrap::init_hitPoints;
	energy = ScavTrap::init_energy;
	attackDamage = FragTrap::init_attackDamage;
	std::cout << "Default constructing a DiamondTrap\n";
}

DiamondTrap::DiamondTrap(std::string const &name)
	: ClapTrap(name + "_clap_name"),
	  FragTrap(name + "_clap_name"), // argument only used for message
	  ScavTrap(name + "_clap_name"), // argument only used for message
	  name(name)
{
	hitPoints = FragTrap::init_hitPoints;
	energy = ScavTrap::init_energy;
	attackDamage = FragTrap::init_attackDamage;
	std::cout << "Constructing DiamondTrap " << name << "\n";
}

DiamondTrap::DiamondTrap(DiamondTrap const &other)
	: ClapTrap(other),
	  FragTrap(other),
	  ScavTrap(other),
	  name(other.name)
{
	std::cout << "Copy-constructing DiamondTrap " << name << "\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructing DiamondTrap " << name << "\n";
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
	std::cout << "Copy-assigning DiamondTrap " << other.name << " over " << name << "\n";
	this->ClapTrap::operator=(other);
	name = other.name;
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap " << name << ", also known as ClapTrap " << ClapTrap::name << ".\n";
}
