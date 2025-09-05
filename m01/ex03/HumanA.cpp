#include "HumanA.hpp"

#include <iostream>
#include <string>

#include "Weapon.hpp"

HumanA::HumanA(const std::string &name, const Weapon &weapon)
	: name(name),
	  weapon(weapon)
{
}

void HumanA::attack() const
{
	std::cout
		<< name
		<< " attacks with their "
		<< weapon.getType()
		<< std::endl;
}
