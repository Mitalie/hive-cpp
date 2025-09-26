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
	bool operator>(Fixed const &rhs) const;
	bool operator<(Fixed const &rhs) const;
	bool operator>=(Fixed const &rhs) const;
	bool operator<=(Fixed const &rhs) const;
	bool operator==(Fixed const &rhs) const;
	bool operator!=(Fixed const &rhs) const;
	Fixed operator+(Fixed const &rhs) const;
	Fixed operator-(Fixed const &rhs) const;
	Fixed operator*(Fixed const &rhs) const;
	Fixed operator/(Fixed const &rhs) const;
	Fixed &operator++();
	Fixed &operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	static Fixed &min(Fixed &lhs, Fixed &rhs);
	static Fixed const &min(Fixed const &lhs, Fixed const &rhs);
	static Fixed &max(Fixed &lhs, Fixed &rhs);
	static Fixed const &max(Fixed const &lhs, Fixed const &rhs);

private:
	int bits;
	int const static numFracBits = 8;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);
