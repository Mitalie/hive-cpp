#pragma once

#include <string>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string const &name);
	ClapTrap(ClapTrap const &other);
	~ClapTrap();
	ClapTrap &operator=(ClapTrap const &other);

	void attack(std::string const &target);
	void takeDamage(unsigned int const amount);
	void beRepaired(unsigned int const amount);

protected:
	std::string name;
	unsigned int hitPoints;
	unsigned int energy;
	unsigned int attackDamage;
};
