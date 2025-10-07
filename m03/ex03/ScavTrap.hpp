#pragma once

#include <string>

#include "ClapTrap.hpp"

class ScavTrap : virtual protected ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string const &name);
	ScavTrap(ScavTrap const &other);
	~ScavTrap();
	ScavTrap &operator=(ScavTrap const &other);

	void attack(std::string const &target);
	void guardGate();

	using ClapTrap::beRepaired;
	using ClapTrap::takeDamage;
};
