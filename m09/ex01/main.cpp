#include <exception>
#include <iostream>

#include "RPN.hpp"

int main(int argc, char *argv[])
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
		while (*expression)
		{
			char symbol = *expression++;
			if (symbol == ' ')
				continue;
			rpn.inputSymbol(symbol);
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
