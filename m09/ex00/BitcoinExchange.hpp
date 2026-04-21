#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
public:
	~BitcoinExchange();
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &);
	BitcoinExchange &operator=(BitcoinExchange);

	// Date is stored as decimal YYYYMMDD for space and comparison efficiency
	typedef unsigned int DateKey;

	// Expected format: YYYY-MM-DD
	static DateKey dateStrToKey(const std::string &date);

	void addExchangeRate(DateKey date, double rate);
	double getExchangeRate(DateKey date) const;

private:
	std::map<DateKey, double> exchangeRates;
};
