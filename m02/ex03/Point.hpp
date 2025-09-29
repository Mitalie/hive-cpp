#pragma once

#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(float const x, float const y);
	Point(Point const &other);
	~Point();
	Fixed const &getX() const;
	Fixed const &getY() const;

private:
	Fixed const x;
	Fixed const y;

	/* It's not possible to modify the const member variables. It's less confusing
	to disallow assignment (by declaring the operator private and not defining it)
	than to make it a no-op or to break the constness promise with const_cast. */
	Point &operator=(Point const &other);
};
