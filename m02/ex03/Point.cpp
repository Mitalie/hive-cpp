#include "Point.hpp"

#include "Fixed.hpp"

Point::Point()
	: x(0), y(0)
{
}

Point::Point(float const x, float const y)
	: x(x), y(y)
{
}

Point::Point(Point const &other)
	: x(other.x), y(other.y)
{
}

Point::~Point()
{
}

Fixed const &Point::getX() const
{
	return x;
}

Fixed const &Point::getY() const
{
	return y;
}

std::ostream &operator<<(std::ostream &os, Point const &fixed)
{
	os << '(' << fixed.getX() << ", " << fixed.getY() << ')';
	return os;
}
