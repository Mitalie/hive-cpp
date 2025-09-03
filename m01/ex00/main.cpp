#include <iostream>

#include "Zombie.hpp"

void testZombie()
{
	Zombie foo("Foo");
	Zombie *bar = new Zombie("Bar");
	Zombie baz("Baz");

	baz.announce();
	bar->announce();
	foo.announce();

	delete bar;
}

int main()
{
	std::cout << "==== Start testing Zombie class ====" << std::endl;
	testZombie();
	std::cout << "==== Finish testing Zombie class ====" << std::endl;
}
