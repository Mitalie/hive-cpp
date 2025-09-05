#pragma once

#include <string>

class Weapon;

class HumanB
{
public:
	HumanB(const std::string &name);
	void attack() const;
	void setWeapon(const Weapon &newWeapon);

private:
	std::string name;
	const Weapon *weapon;
};
