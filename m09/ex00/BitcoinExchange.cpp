#include "BitcoinExchange.hpp"

#include <ios>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
	: exchangeRates(other.exchangeRates)
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange copy)
{
	exchangeRates.swap(copy.exchangeRates);
	return *this;
}

void BitcoinExchange::addExchangeRate(DateKey date, double rate)
{
	exchangeRates[date] = rate;
}

double BitcoinExchange::getExchangeRate(DateKey date) const
{
	// We want the rate for the queried date, or closest previous date if not found
	// lower_bound would find the exact match or next higher, so we'd need to check for both end()
	// (past last date) and the date value to see if we want the found entry or the previous entry.
	// upper_bound finds next higher, so we go to the previous entry without unnecessary checks.
	// Either way, we need to check for begin() to avoid decrementing past the first entry.

	std::map<DateKey, double>::const_iterator it = exchangeRates.upper_bound(date);
	if (it == exchangeRates.begin())
		throw std::out_of_range("Date before first known date");
	return (--it)->second;
}

static const unsigned int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static bool isValidDate(unsigned int year, unsigned int month, unsigned int day)
{
	if (year > 9999 || month == 0 || month > 12 || day == 0)
		return false;
	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	unsigned int maxDay = daysInMonth[month - 1];
	if (month == 2 && isLeapYear)
		maxDay = 29;
	return day <= maxDay;
}

BitcoinExchange::DateKey BitcoinExchange::dateStrToKey(const std::string &date)
{
	std::istringstream iss(date);
	iss >> std::noskipws; // Disallow extra whitespace
	unsigned int year, month, day;
	char sep1, sep2;
	iss >> year >> sep1 >> month >> sep2 >> day;
	if (!iss || sep1 != '-' || sep2 != '-')
		throw std::invalid_argument("Invalid date format");
	if (!iss.eof())
		throw std::invalid_argument("Extra characters after date");
	if (!isValidDate(year, month, day))
		throw std::invalid_argument("Invalid date value");
	return year * 10000 + month * 100 + day;
}
