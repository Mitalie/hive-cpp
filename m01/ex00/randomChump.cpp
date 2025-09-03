#include "zombieUtils.hpp"

#include <string>

#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie z(name);
	z.announce();
}
