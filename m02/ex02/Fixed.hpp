#pragma once

#include <ostream>

class Fixed
{
public:
	Fixed();
	Fixed(Fixed const &other);
	Fixed(int const value);
	Fixed(float const value);
	Fixed &operator=(Fixed const &other);
	~Fixed();
	int toInt() const;
	float toFloat() const;
	int getRawBits() const;
	void setRawBits(int const raw);

private:
	int bits;
	int const static numFracBits = 8;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);
