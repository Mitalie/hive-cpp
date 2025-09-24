#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed()
	: bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other)
	: bits(other.bits)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(int const value)
	: bits(value << numFracBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value)
	: bits(roundf(value * (1 << numFracBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	bits = other.bits;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return bits;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	bits = raw;
}

int Fixed::toInt() const
{
	// Can't just increment by half and round down - the addition could overflow
	int const whole = bits >> numFracBits;
	int const halfBit = 1 << (numFracBits - 1);
	bool const fracIsHalfOrGreater = bits & halfBit;
	return whole + fracIsHalfOrGreater;
}

float Fixed::toFloat() const
{
	int const scale = 1 << numFracBits;
	return static_cast<float>(bits) / scale;
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return os;
}
