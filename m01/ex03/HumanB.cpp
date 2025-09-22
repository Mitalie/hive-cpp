#include "HumanB.hpp"

#include <iostream>
#include <string>

#include "Weapon.hpp"

HumanB::HumanB(const std::string &name)
	: name(name),
	  weapon(0)
{
}

void HumanB::attack() const
{
	std::cout
		<< name
		<< " attacks with their "
		<< (weapon ? weapon->getType() : "fists")
		<< std::endl;
}

void HumanB::setWeapon(const Weapon &newWeapon)
{
	weapon = &newWeapon;
}
