#include "ScalarConverter.hpp"

#include <cmath>
#include <cstddef>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <sstream>

// static_cast does not change the value for the same type, so a single function template can be used for all types
template <typename T>
void printValue(T value)
{
	// Consider NaN and out-of-range values as impossible for char and int. Also avoid printing non-printable characters for char.
	if (std::isnan(value) || value < 0 || value > std::numeric_limits<char>::max())
		std::cout << "char: impossible\n";
	else if (value < 32 || value > 126)
		std::cout << "char: non-printable\n";
	else
		std::cout << "char: '" << static_cast<char>(value) << "'\n";

	if (std::isnan(value) || value < std::numeric_limits<int>::min() || value > (double)std::numeric_limits<int>::max())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(value) << '\n';

	// Float and double are never impossible, but ensure that we print a decimal point and a zero for whole numbers.
	float fv = static_cast<float>(value);
	std::string fstr = (std::ostringstream() << fv).str();
	if (std::isfinite(fv) && fstr.find('.') == std::string::npos)
		fstr += ".0";
	std::cout << "float: " << fstr << "f\n";

	double dv = static_cast<double>(value);
	std::string dstr = (std::ostringstream() << dv).str();
	if (std::isfinite(dv) && dstr.find('.') == std::string::npos)
		dstr += ".0";
	std::cout << "double: " << dstr << '\n';
}

bool handleCharLiteral(std::string const &input)
{
	// char literals must be exactly three characters, starting and ending with a single quote
	if (input.length() != 3 || input[0] != '\'' || input[2] != '\'')
		return false;
	char value = input[1];
	printValue(value);
	return true;
}

bool handleIntLiteral(std::string const &input)
{
	try
	{
		// int literals must be entirely consumed by std::stoi
		size_t parsedLen;
		int value = std::stoi(input, &parsedLen);
		if (parsedLen != input.length())
			return false;
		printValue(value);
		return true;
	}
	catch (std::invalid_argument const &e)
	{
		return false;
	}
	catch (std::out_of_range const &e)
	{
		return false;
	}
}

bool handleFloatLiteral(std::string const &input)
{
	try
	{
		// float literals must end with an 'f', and otherwise be entirely consumed by std::stof
		if (input.back() != 'f')
			return false;
		size_t parsedLen;
		float value = std::stof(input, &parsedLen);
		if (parsedLen != input.length() - 1)
			return false;
		printValue(value);
		return true;
	}
	catch (std::invalid_argument const &e)
	{
		return false;
	}
	catch (std::out_of_range const &e)
	{
		return false;
	}
}

bool handleDoubleLiteral(std::string const &input)
{
	try
	{
		// double literals must be entirely consumed by std::stod
		size_t parsedLen;
		double value = std::stod(input, &parsedLen);
		if (parsedLen != input.length())
			return false;
		printValue(value);
		return true;
	}
	catch (std::invalid_argument const &e)
	{
		return false;
	}
	catch (std::out_of_range const &e)
	{
		return false;
	}
}

void ScalarConverter::convert(std::string const &input)
{
	if (handleCharLiteral(input))
		return;
	if (handleIntLiteral(input))
		return;
	if (handleFloatLiteral(input))
		return;
	if (handleDoubleLiteral(input))
		return;
	std::cout << "Unrecognized literal\n";
}
