#pragma once

#include <string>

class Weapon;

class HumanA
{
public:
	HumanA(const std::string &name, const Weapon &weapon);
	void attack() const;

private:
	std::string name;
	const Weapon &weapon;
};
