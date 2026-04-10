#include "ScalarConverter.hpp"

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
void printValue(T value)
{
	// TODO
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
