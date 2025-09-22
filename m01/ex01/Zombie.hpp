#pragma once

#include <string>

class Zombie
{
private:
	std::string name;

public:
	Zombie();
	Zombie(const std::string &name);
	~Zombie();
	void announce() const;
};
