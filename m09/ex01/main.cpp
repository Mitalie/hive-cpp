#include <exception>
#include <iostream>

#include "RPN.hpp"

int rpn_main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <RPN expression>\n";
		return 1;
	}

	RPN rpn;
	const char *expression = argv[1];

	try
	{
		if (*expression == ' ')
			expression++; // Tolerate one leading space
		while (*expression)
		{
			char symbol = *expression++;
			if (symbol == ' ')
				throw std::runtime_error("Multiple spaces");
			rpn.inputSymbol(symbol);
			// Consume one space after symbol, tolerate one trailing space
			if (*expression && *expression++ != ' ')
				throw std::runtime_error("Space expected between symbols");
		}
		std::cout << rpn.getResult() << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return 1;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	try
	{
		return rpn_main(argc, argv);
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
