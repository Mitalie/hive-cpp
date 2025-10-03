#pragma once

#include <string>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string const &name);
	FragTrap(FragTrap const &other);
	~FragTrap();
	FragTrap &operator=(FragTrap const &other);

	void highFivesGuys();
};
