#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

void test5()
{
	std::cout << BY << "==== Test5: ScavTrap, sub-type of ClapTrap with inherited members ====" << RN;
	{
		std::cout << DY << "[Test5] constructing local ScavTrap \"scav\"" << RN;
		ScavTrap scav("Scavvy");
		std::cout << DY << "[Test5] testing ScavTrap functions" << RN;
		scav.attack("a bandit");
		scav.guardGate();
		std::cout << DY << "[Test5] testing inherited functions" << RN;
		scav.takeDamage(4);
		scav.beRepaired(3);
		std::cout << DY << "[Test5] exiting scope" << RN;
	}
	std::cout << BY << "==== Test5 done ====" << RN;
}

void test6()
{
	std::cout << BY << "==== Test6: ScavTrap copy construction and assignment ====" << RN;
	{
		std::cout << DY << "[Test6] constructing local \"one\"" << RN;
		ScavTrap one("Scavvy");
		std::cout << DY << "[Test6] \"one\" acts" << RN;
		one.attack("a bandit");
		one.takeDamage(4);
		one.beRepaired(3);
		one.guardGate();

		std::cout << DY << "[Test6] constructing local \"two\" as copy of \"one\"" << RN;
		ScavTrap two(one);
		std::cout << DY << "[Test6] \"two\" acts" << RN;
		two.attack("a stalker");
		two.takeDamage(6);
		two.beRepaired(2);
		two.guardGate();

		std::cout << DY << "[Test6] constructing local \"three\"" << RN;
		ScavTrap three;
		std::cout << DY << "[Test6] \"three\" acts" << RN;
		three.attack("a loader");
		three.takeDamage(2);
		three.beRepaired(1);
		three.guardGate();

		std::cout << DY << "[Test6] assigning \"two\" over \"three\"" << RN;
		three = two;
		std::cout << DY << "[Test6] \"three\" acts" << RN;
		three.attack("an eridian");
		three.takeDamage(2);
		three.beRepaired(1);
		three.guardGate();

		std::cout << DY << "[Test6] exiting scope" << RN;
	}
	std::cout << BY << "==== Test6 done ====" << RN;
}

void test7()
{
	std::cout << BY << "==== Test7: FragTrap, sub-type with inherited members ====" << RN;
	{
		std::cout << DY << "[Test7] constructing local FragTrap \"frag\"" << RN;
		FragTrap frag("Fraggy");
		std::cout << DY << "[Test7] testing FragTrap functions" << RN;
		frag.highFivesGuys();
		std::cout << DY << "[Test7] testing inherited functions" << RN;
		frag.attack("a bandit");
		frag.takeDamage(4);
		frag.beRepaired(3);
		std::cout << DY << "[Test7] exiting scope" << RN;
	}
	std::cout << BY << "==== Test7 done ====" << RN;
}

void test8()
{
	std::cout << BY << "==== Test8: FragTrap copy construction and assignment ====" << RN;
	{
		std::cout << DY << "[Test8] constructing local \"one\"" << RN;
		FragTrap one("Fraggy");
		std::cout << DY << "[Test8] \"one\" acts" << RN;
		one.attack("a bandit");
		one.takeDamage(4);
		one.beRepaired(3);
		one.highFivesGuys();

		std::cout << DY << "[Test8] constructing local \"two\" as copy of \"one\"" << RN;
		FragTrap two(one);
		std::cout << DY << "[Test8] \"two\" acts" << RN;
		two.attack("a stalker");
		two.takeDamage(6);
		two.beRepaired(2);
		two.highFivesGuys();

		std::cout << DY << "[Test8] constructing local \"three\"" << RN;
		FragTrap three;
		std::cout << DY << "[Test8] \"three\" acts" << RN;
		three.attack("a loader");
		three.takeDamage(2);
		three.beRepaired(1);
		three.highFivesGuys();

		std::cout << DY << "[Test8] assigning \"two\" over \"three\"" << RN;
		three = two;
		std::cout << DY << "[Test8] \"three\" acts" << RN;
		three.attack("an eridian");
		three.takeDamage(2);
		three.beRepaired(1);
		three.highFivesGuys();

		std::cout << DY << "[Test8] exiting scope" << RN;
	}
	std::cout << BY << "==== Test8 done ====" << RN;
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
}
