#pragma once

#include <string>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string const &name);
	ScavTrap(ScavTrap const &other);
	~ScavTrap();
	ScavTrap &operator=(ScavTrap const &other);

	void guardGate();
};
