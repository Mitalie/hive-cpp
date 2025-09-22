#include <exception>
#include <iostream>

#include "Zombie.hpp"
#include "zombieUtils.hpp"

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

void testZombieUtils()
{
	Zombie *foo = newZombie("Foo");
	randomChump("Wan");
	Zombie *bar = newZombie("Bar");

	foo->announce();
	delete foo;
	randomChump("Too");
	bar->announce();
	delete bar;
}

void brainzTest_main()
{
	std::cout << "==== Start testing Zombie class ====" << std::endl;
	testZombie();
	std::cout << "==== Finish testing Zombie class ====" << std::endl;
	std::cout << "==== Start testing Zombie utils ====" << std::endl;
	testZombieUtils();
	std::cout << "==== Finish testing Zombie utils ====" << std::endl;
}

int main()
{
	try
	{
		brainzTest_main();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	catch (...)
	{
		std::cerr << "Unknown exception" << std::endl;
		return 1;
	}
}
