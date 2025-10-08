#pragma once

#include <string>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : private FragTrap, private ScavTrap
{
public:
	DiamondTrap();
	DiamondTrap(std::string const &name);
	DiamondTrap(DiamondTrap const &other);
	~DiamondTrap();
	DiamondTrap &operator=(DiamondTrap const &other);

	void whoAmI();

	using ClapTrap::beRepaired;
	using ClapTrap::takeDamage;
	using FragTrap::highFivesGuys;
	using ScavTrap::attack;
	using ScavTrap::guardGate;

private:
	std::string name;
};
