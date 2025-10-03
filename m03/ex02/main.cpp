#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

void test1()
{
	std::cout << "==== Test1: sub-type with inherited members ====\n";
	{
		std::cout << "[Test1] constructing local FragTrap \"frag\"\n";
		FragTrap frag("Fraggy");
		std::cout << "[Test1] accessing as FragTrap\n";
		frag.attack("a bandit");
		frag.takeDamage(4);
		frag.beRepaired(3);
		frag.highFivesGuys();

		std::cout << "[Test1] creating ClapTrap-typed reference to \"frag\"\n";
		ClapTrap &clap = frag;
		std::cout << "[Test1] accessing as ClapTrap\n";
		clap.attack("a stalker");
		clap.takeDamage(6);
		clap.beRepaired(5);
		// clap.highFivesGuys(); // this line should not compile
		std::cout << "[Test1] exiting scope\n";
	}
	std::cout << "==== Test1 done ====\n";
}

void test2()
{
	std::cout << "==== Test2: copy construction and assignment ====\n";
	{
		std::cout << "[Test2] constructing local \"one\"\n";
		FragTrap one("Fraggy");
		std::cout << "[Test2] \"one\" acts\n";
		one.attack("a bandit");
		one.takeDamage(4);
		one.beRepaired(3);
		one.highFivesGuys();

		std::cout << "[Test2] constructing local \"two\" as copy of \"one\"\n";
		FragTrap two(one);
		std::cout << "[Test2] \"two\" acts\n";
		two.attack("a stalker");
		two.takeDamage(6);
		two.beRepaired(2);
		two.highFivesGuys();

		std::cout << "[Test2] constructing local \"three\"\n";
		FragTrap three;
		std::cout << "[Test2] \"three\" acts\n";
		three.attack("a loader");
		three.takeDamage(2);
		three.beRepaired(1);
		three.highFivesGuys();

		std::cout << "[Test2] assigning \"two\" over \"three\"\n";
		three = two;
		std::cout << "[Test2] \"three\" acts\n";
		three.attack("an eridian");
		three.takeDamage(2);
		three.beRepaired(1);
		three.highFivesGuys();

		std::cout << "[Test2] exiting scope\n";
	}
	std::cout << "==== Test2 done ====\n";
}

int main()
{
	test1();
	test2();
}
