#include "ScalarConverter.hpp"

#include <cmath>
#include <cstddef>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

bool handleCharLiteral(std::string const &input)
{
	// must be 3-char string that starts and ends with single quote
	if (input.length() != 3 || input[0] != '\'' || input[2] != '\'')
		return false;
	char v = input[1];
	if (v < 32 || v > 126)
		std::cout << "char: Non-printable character\n";
	else
		std::cout << "char: '" << v << "'\n";
	std::cout << "int: " << static_cast<int>(v) << '\n';
	std::cout << "float: " << static_cast<float>(v) << '\n';
	std::cout << "double: " << static_cast<double>(v) << '\n';
	return true;
}

bool handleIntLiteral(std::string const &input)
{
	try
	{
		// must be entirely consumed by std::stoi
		size_t parsedLen;
		int v = std::stoi(input, &parsedLen);
		if (parsedLen != input.length())
			return false;
		if (v < 0 || v > std::numeric_limits<char>::max())
			std::cout << "char: impossible\n";
		else if (v < 32 || v > 126)
			std::cout << "char: Non-printable character\n";
		else
			std::cout << "char: '" << static_cast<char>(v) << "'\n";
		std::cout << "int: " << v << '\n';
		std::cout << "float: " << static_cast<float>(v) << '\n';
		std::cout << "double: " << static_cast<double>(v) << '\n';
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
	// float literals always end with an extra 'f'
	if (input.back() != 'f')
		return false;
	try
	{
		// must be entirely consumed by std::stof, except for the trailing 'f'
		size_t parsedLen;
		float v = std::stof(input, &parsedLen);
		if (parsedLen != input.length() - 1)
			return false;
		if (std::isnan(v) || v < 0 || v > std::numeric_limits<char>::max())
			std::cout << "char: impossible\n";
		else if (v < 32 || v > 126)
			std::cout << "char: Non-printable character\n";
		else
			std::cout << "char: '" << static_cast<char>(v) << "'\n";
		if (std::isnan(v) || v < std::numeric_limits<int>::min() || v > (double)std::numeric_limits<int>::max())
			std::cout << "int: impossible\n";
		else
			std::cout << "int: " << static_cast<int>(v) << '\n';
		std::cout << "float: " << v << "f\n";
		std::cout << "double: " << static_cast<double>(v) << '\n';
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
		// must be entirely consumed by std::stod
		size_t parsedLen;
		double v = std::stod(input, &parsedLen);
		if (parsedLen != input.length())
			return false;
		if (std::isnan(v) || v < 0 || v > std::numeric_limits<char>::max())
			std::cout << "char: impossible\n";
		else if (v < 32 || v > 126)
			std::cout << "char: Non-printable character\n";
		else
			std::cout << "char: '" << static_cast<char>(v) << "'\n";
		if (std::isnan(v) || v < std::numeric_limits<int>::min() || v > (double)std::numeric_limits<int>::max())
			std::cout << "int: impossible\n";
		else
			std::cout << "int: " << static_cast<int>(v) << '\n';
		if (!std::isinf(v) && (v < std::numeric_limits<float>::min() || v > std::numeric_limits<float>::max()))
			std::cout << "float: impossible\n";
		else
			std::cout << "float: " << v << "f\n";
		std::cout << "double: " << static_cast<double>(v) << '\n';
		return true;
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
