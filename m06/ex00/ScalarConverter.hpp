#pragma once

#include <string>

class ScalarConverter
{
public:
	static void convert(const std::string &input);

private:
	// Disable automatic member functions
	~ScalarConverter();
	ScalarConverter();
	ScalarConverter(ScalarConverter const &);
	ScalarConverter operator=(ScalarConverter const &);
};
