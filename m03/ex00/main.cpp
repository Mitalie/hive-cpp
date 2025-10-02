#include <iostream>

#include "ClapTrap.hpp"

void test1()
{
	std::cout << "==== Test1: constructing and messages ====\n";
	{
		std::cout << "[Test1] constructing local \"def\" and \"two\"\n";
		ClapTrap def;
		ClapTrap two("Two");

		std::cout << "[Test1] \"def\" acts\n";
		def.attack("a bandit");
		def.takeDamage(4);
		def.beRepaired(3);
		std::cout << "[Test1] \"two\" acts\n";
		two.attack("a stalker");
		two.takeDamage(1);
		two.beRepaired(2);
		std::cout << "[Test1] exiting scope\n";
	}
	std::cout << "==== Test1 done ====\n";
}

void test2()
{
	std::cout << "==== Test2: hit points ====\n";
	{
		std::cout << "[Test2] constructing local \"clap\"\n";
		ClapTrap clap("Clappy");

		std::cout << "[Test2] \"clap\" acts\n";
		clap.attack("a bandit");
		clap.takeDamage(6);
		clap.beRepaired(3);
		clap.attack("another bandit");
		clap.takeDamage(6);
		clap.beRepaired(3);
		clap.attack("a third bandit");
		clap.takeDamage(6);
		clap.beRepaired(3);
		clap.attack("a fourth bandit");
		clap.takeDamage(6);
		clap.beRepaired(3);
		clap.attack("a fifth bandit");
		std::cout << "[Test2] exiting scope\n";
	}
	std::cout << "==== Test2 done ====\n";
}

void test3()
{
	std::cout << "==== Test3: energy ====\n";
	{
		std::cout << "[Test3] constructing local \"clap\"\n";
		ClapTrap clap("Clappy");

		std::cout << "[Test3] \"clap\" acts\n";
		clap.attack("a bandit");
		clap.attack("a bandit");
		clap.beRepaired(1);
		clap.attack("a bandit");
		clap.attack("a bandit");
		clap.beRepaired(1);
		clap.beRepaired(1);
		clap.attack("a bandit");
		clap.beRepaired(1);
		clap.beRepaired(1);
		clap.beRepaired(1);
		clap.beRepaired(1);
		clap.attack("a bandit");
		clap.attack("a bandit");
		clap.takeDamage(0);
		std::cout << "[Test3] exiting scope\n";
	}
	std::cout << "==== Test3 done ====\n";
}

void test4()
{
	std::cout << "==== Test4: instances and assignment ====\n";
	{
		std::cout << "[Test4] constructing local \"def\" and \"two\"\n";
		ClapTrap def;
		ClapTrap two("Two");

		std::cout << "[Test4] \"def\" acts\n";
		def.attack("a bandit");
		def.takeDamage(10);
		def.attack("a bandit");
		std::cout << "[Test4] \"two\" acts\n";
		two.takeDamage(1);
		std::cout << "[Test4] assigning \"two\" to \"def\"\n";
		def = two;
		std::cout << "[Test4] \"two\" acts\n";
		two.takeDamage(9);
		two.attack("a stalker");
		std::cout << "[Test4] \"def\" acts\n";
		def.takeDamage(1);
		def.attack("a stalker");
		std::cout << "[Test4] exiting scope\n";
	}
	std::cout << "==== Test4 done ====\n";
}

int main()
{
	test1();
	test2();
	test3();
	test4();
}
