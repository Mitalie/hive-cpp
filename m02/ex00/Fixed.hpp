#pragma once

class Fixed
{
public:
	Fixed();
	Fixed(Fixed const &other);
	Fixed &operator=(Fixed const &other);
	~Fixed();
	int getRawBits() const;
	void setRawBits(int const raw);

private:
	int bits;
	int const static numFracBits = 8;
};
