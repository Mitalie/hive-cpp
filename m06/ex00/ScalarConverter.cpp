#include "ScalarConverter.hpp"

#include <cstddef>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

template <typename T>
void printChar(T v)
{
	char cv = static_cast<char>(v);
	if (v < 0 || v > std::numeric_limits<char>::max())
		std::cout << "char: Impossible\n";
	else if (cv < 32 || cv > 126)
		std::cout << "char: Non-printable character\n";
	else
		std::cout << "char: '" << cv << "'\n";
}

template <typename T>
void printInt(T v)
{
	int iv = static_cast<int>(v);
	if (v < std::numeric_limits<int>::min() || v > (double)std::numeric_limits<int>::max())
		std::cout << "int: Impossible\n";
	else
		std::cout << "int: " << iv << '\n';
}

template <typename T>
void printFloat(T v)
{
	float fv = static_cast<float>(v);
	if (v < std::numeric_limits<float>::min() || v > std::numeric_limits<float>::max())
		std::cout << "float: Impossible\n";
	else
		std::cout << "float: " << fv << '\n';
}

template <typename T>
void printDouble(T v)
{
	double dv = static_cast<double>(v);
	std::cout << "double: " << dv << '\n';
}

template <typename T>
void printAll(T v)
{
	printChar(v);
	printInt(v);
	printFloat(v);
	printDouble(v);
}

bool handleCharLiteral(std::string const &input)
{
	// must be 3-char string that starts and ends with single quote
	if (input.length() != 3 || input[0] != '\'' || input[2] != '\'')
		return false;
	printAll(input[1]);
	return true;
}

bool handleIntLiteral(std::string const &input)
{
	size_t parsedLen;
	int value;
	try
	{
		// must be entirely consumed by std::stoi
		value = std::stoi(input, &parsedLen);
		if (parsedLen != input.length())
			return false;
		printAll(value);
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
	size_t parsedLen;
	float value;
	try
	{
		// must be entirely consumed by std::stof, except for the trailing 'f'
		value = std::stof(input, &parsedLen);
		if (parsedLen != input.length() - 1)
			return false;
		printAll(value);
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
	size_t parsedLen;
	double value;
	try
	{
		// must be entirely consumed by std::stod
		value = std::stod(input, &parsedLen);
		if (parsedLen != input.length())
			return false;
		printAll(value);
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
