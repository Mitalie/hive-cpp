#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "BitcoinExchange.hpp"

#define RED "\033[31m"
#define RESET "\033[0m"
#define RESETNL "\033[0m\n"

static std::string trim(const std::string &str)
{
	std::string::size_type first = str.find_first_not_of(" \t");
	if (first == std::string::npos)
		return "";
	std::string::size_type last = str.find_last_not_of(" \t");
	return str.substr(first, last - first + 1);
}

typedef bool IsHeaderFunc(const std::string &line);
typedef void HandleLineFunc(const std::string &line, BitcoinExchange &exchange);

// Shared file handling logic: read lines, skip header if detected, call line handler for each line
static void handleFile(std::ifstream &file, IsHeaderFunc isHeader, HandleLineFunc handleLine, BitcoinExchange &exchange)
{
	bool maybeHeader = true;
	while (file)
	{
		std::string line;
		std::getline(file, line);
		// First line may be a header, skip
		if (maybeHeader)
		{
			maybeHeader = false;
			if (isHeader(line))
				continue;
		}
		handleLine(line, exchange);
		if (file.peek() == std::istringstream::traits_type::eof())
			break;
	}
}

// Shared line-parsing logic: parse date and a double value with a separator, throw on format error or invalid date
static void parseDateAndDouble(const std::string &line, char separator, std::string &dateStr, BitcoinExchange::DateKey &date, double &value)
{
	std::istringstream iss(line);
	if (!std::getline(iss, dateStr, separator))
		throw std::runtime_error("Invalid line format");

	dateStr = trim(dateStr);
	try
	{
		date = BitcoinExchange::dateStrToKey(dateStr);
	}
	catch (const std::invalid_argument &e)
	{
		throw std::runtime_error(std::string("Invalid date: ") + e.what());
	}

	iss >> value;
	if (!iss)
		throw std::runtime_error("Invalid line format");
	if (!iss.eof())
		iss >> std::ws; // Ignore trailing whitespace
	if (!iss.eof())
		throw std::runtime_error("Extra characters after value");
}

// CSV header detection
static bool isCSVHeader(const std::string &line)
{
	std::istringstream iss(line);
	std::string first, second;
	if (!std::getline(iss, first, ',') || !std::getline(iss, second))
		return false;
	return trim(first) == "date" && trim(second) == "exchange_rate";
}

// CSV-specific line handling: store data in exchange object, throw on error
static void handleCSVLine(const std::string &line, BitcoinExchange &exchange)
{

	try
	{
		std::string dateStr;
		BitcoinExchange::DateKey date;
		double rate;
		parseDateAndDouble(line, ',', dateStr, date, rate);
		exchange.addExchangeRate(date, rate);
	}
	catch (const std::runtime_error &e)
	{
		throw std::runtime_error(std::string("Error parsing line: ") + e.what() + "; line: " + line);
	}
}

// Input header detection
static bool isInputHeader(const std::string &line)
{
	std::istringstream iss(line);
	std::string first, second;
	if (!std::getline(iss, first, '|') || !std::getline(iss, second))
		return false;
	return trim(first) == "date" && trim(second) == "value";
}

// Input-specific line handling: query exchange object and print result, print message on error
static void handleInputLine(const std::string &line, BitcoinExchange &exchange)
{
	try
	{
		std::string dateStr;
		BitcoinExchange::DateKey date;
		double value;
		parseDateAndDouble(line, '|', dateStr, date, value);

		double rate;
		try
		{
			rate = exchange.getExchangeRate(date);
		}
		catch (const std::out_of_range &e)
		{
			throw std::runtime_error(std::string("Could not find exchange rate: ") + e.what());
		}

		if (value < 0 || value > 1000)
			throw std::runtime_error("Value out of range [0, 1000]");

		std::cout << dateStr << " => " << value << " = " << value * rate << '\n';
	}
	catch (const std::runtime_error &e)
	{
		std::cout << RED "Bad input >" RESET << line << RED "<, error: " << e.what() << RESETNL;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <input_file>\n";
		return 1;
	}
	std::ifstream csvFile("data.csv");
	if (!csvFile.is_open())
	{
		std::cerr << "Error: Could not open exchange data file: data.csv\n";
		return 1;
	}
	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Could not open input file: " << argv[1] << "\n";
		return 1;
	}
	BitcoinExchange exchange;
	try
	{
		handleFile(csvFile, isCSVHeader, handleCSVLine, exchange);
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << "Error loading exchange data: " << e.what() << "\n";
		return 1;
	}
	handleFile(inputFile, isInputHeader, handleInputLine, exchange);
	return 0;
}
