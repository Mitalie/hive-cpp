#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void test1()
{
	std::cout << "==== Test1: sub-type with inherited members ====\n";
	{
		std::cout << "[Test1] constructing local ScavTrap \"scav\"\n";
		ScavTrap scav("Scavvy");
		std::cout << "[Test1] accessing as ScavTrap\n";
		scav.attack("a bandit");
		scav.takeDamage(4);
		scav.beRepaired(3);
		scav.guardGate();

		std::cout << "[Test1] creating ClapTrap-typed reference to \"scav\"\n";
		ClapTrap &clap = scav;
		std::cout << "[Test1] accessing as ClapTrap\n";
		clap.attack("a stalker");
		clap.takeDamage(6);
		clap.beRepaired(5);
		// clap.guardGate(); // this line should not compile
		std::cout << "[Test1] exiting scope\n";
	}
	std::cout << "==== Test1 done ====\n";
}

int main()
{
	test1();
}
