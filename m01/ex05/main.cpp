#include <exception>
#include <iostream>

#include "Harl.hpp"

void harl_main()
{
	Harl harl;

	std::cout << "==== Test complaints in default order (D-I-W-E) ====" << std::endl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	std::cout << "==== Test complaints in modified order (E-I-D-W) ====" << std::endl;
	harl.complain("ERROR");
	harl.complain("INFO");
	harl.complain("DEBUG");
	harl.complain("WARNING");

	std::cout << "==== Done ====" << std::endl;
}

int main()
{
	try
	{
		harl_main();
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
