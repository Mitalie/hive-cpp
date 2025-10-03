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

void test2()
{
	std::cout << "==== Test2: copy construction and assignment ====\n";
	{
		std::cout << "[Test2] constructing local \"one\"\n";
		ScavTrap one("Scavvy");
		std::cout << "[Test2] \"one\" acts\n";
		one.attack("a bandit");
		one.takeDamage(4);
		one.beRepaired(3);
		one.guardGate();

		std::cout << "[Test2] constructing local \"two\" as copy of \"one\"\n";
		ScavTrap two(one);
		std::cout << "[Test2] \"two\" acts\n";
		two.attack("a stalker");
		two.takeDamage(6);
		two.beRepaired(2);
		two.guardGate();

		std::cout << "[Test2] constructing local \"three\"\n";
		ScavTrap three;
		std::cout << "[Test2] \"three\" acts\n";
		three.attack("a loader");
		three.takeDamage(2);
		three.beRepaired(1);
		three.guardGate();

		std::cout << "[Test2] assigning \"two\" over \"three\"\n";
		three = two;
		std::cout << "[Test2] \"three\" acts\n";
		three.attack("an eridian");
		three.takeDamage(2);
		three.beRepaired(1);
		three.guardGate();

		std::cout << "[Test2] exiting scope\n";
	}
	std::cout << "==== Test2 done ====\n";
}

int main()
{
	test1();
	test2();
}
