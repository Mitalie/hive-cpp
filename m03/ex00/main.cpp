#include <iostream>

#include "ClapTrap.hpp"

static const char BY[] = "\x1b[93m";  // Bright yellow
static const char DY[] = "\x1b[33m";  // Dim yellow
static const char RN[] = "\x1b[0m\n"; // Reset style and newline

void test1()
{
	std::cout << BY << "==== Test1: ClapTrap constructing and messages ====" << RN;
	{
		std::cout << DY << "[Test1] constructing local \"def\" and \"two\"" << RN;
		ClapTrap def;
		ClapTrap two("Two");

		std::cout << DY << "[Test1] \"def\" acts" << RN;
		def.attack("a bandit");
		def.takeDamage(4);
		def.beRepaired(3);
		std::cout << DY << "[Test1] \"two\" acts" << RN;
		two.attack("a stalker");
		two.takeDamage(1);
		two.beRepaired(2);
		std::cout << DY << "[Test1] exiting scope" << RN;
	}
	std::cout << BY << "==== Test1 done ====" << RN;
}

void test2()
{
	std::cout << BY << "==== Test2: ClapTrap hit points ====" << RN;
	{
		std::cout << DY << "[Test2] constructing local \"clap\"" << RN;
		ClapTrap clap("Clappy");

		std::cout << DY << "[Test2] \"clap\" acts" << RN;
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
		std::cout << DY << "[Test2] exiting scope" << RN;
	}
	std::cout << BY << "==== Test2 done ====" << RN;
}

void test3()
{
	std::cout << BY << "==== Test3: ClapTrap energy ====" << RN;
	{
		std::cout << DY << "[Test3] constructing local \"clap\"" << RN;
		ClapTrap clap("Clappy");

		std::cout << DY << "[Test3] \"clap\" acts" << RN;
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
		std::cout << DY << "[Test3] exiting scope" << RN;
	}
	std::cout << BY << "==== Test3 done ====" << RN;
}

void test4()
{
	std::cout << BY << "==== Test4: ClapTrap instances and assignment ====" << RN;
	{
		std::cout << DY << "[Test4] constructing local \"def\" and \"two\"" << RN;
		ClapTrap def;
		ClapTrap two("Two");

		std::cout << DY << "[Test4] \"def\" acts" << RN;
		def.attack("a bandit");
		def.takeDamage(10);
		def.attack("a bandit");
		std::cout << DY << "[Test4] \"two\" acts" << RN;
		two.takeDamage(1);
		std::cout << DY << "[Test4] assigning \"two\" to \"def\"" << RN;
		def = two;
		std::cout << DY << "[Test4] \"two\" acts" << RN;
		two.takeDamage(9);
		two.attack("a stalker");
		std::cout << DY << "[Test4] \"def\" acts" << RN;
		def.takeDamage(1);
		def.attack("a stalker");
		std::cout << DY << "[Test4] exiting scope" << RN;
	}
	std::cout << BY << "==== Test4 done ====" << RN;
}

int main()
{
	test1();
	test2();
	test3();
	test4();
}
