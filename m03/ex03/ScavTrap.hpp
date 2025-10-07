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

protected:
	static const unsigned int init_hitPoints = 100;
	static const unsigned int init_energy = 50;
	static const unsigned int init_attackDamage = 20;
};
