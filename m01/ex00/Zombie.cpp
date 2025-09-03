#include "Zombie.hpp"

#include <iostream>
#include <string>

Zombie::Zombie(const std::string &name)
	: name(name)
{
	std::cerr << "[debug] Constructing zombie \"" << name << "\"" << std::endl;
}

Zombie::~Zombie()
{
	std::cerr << "[debug] Destructing zombie \"" << name << "\"" << std::endl;
}

void Zombie::announce() const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
