#include <exception>
#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
		{
			std::cout << "Requires exactly one argument\n";
			return 1;
		}
		ScalarConverter::convert(argv[1]);
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
