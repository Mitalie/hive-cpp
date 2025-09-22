#include <exception>
#include <iostream>

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

void violence_main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		// The line below was not in the example, but was added to show that
		// HumanB::attack() doesn't dereference uninitialized or null pointers.
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}

int main()
{
	try
	{
		violence_main();
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
