#include "Weapon.hpp"

#include <string>

Weapon::Weapon(const std::string &type)
	: type(type)
{
}

const std::string &Weapon::getType() const
{
	return type;
}

void Weapon::setType(const std::string &newType)
{
	type = newType;
}
