#include <exception>
#include <iostream>

#include "Zombie.hpp"
#include "zombieHorde.hpp"

void brainzTest_main()
{
	const int N = 5;

	std::cout << "==== Creating zombie horde ====" << std::endl;
	Zombie *horde = zombieHorde(N, "Graaah");
	std::cout << "==== Announcing zombie horde ====" << std::endl;
	for (int i = 0; i < N; ++i)
		horde[i].announce();
	std::cout << "==== Deleting zombie horde ====" << std::endl;
	delete[] horde;
	std::cout << "==== Done ====" << std::endl;
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
