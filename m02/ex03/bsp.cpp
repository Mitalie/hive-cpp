#include "bsp.hpp"

#include "Fixed.hpp"
#include "Point.hpp"

/*
	Determines on which side of the line AB the point P lies, as if observed from A looking towards B.

	Retuns +1 for left side, -1 for right side, and 0 for exactly on the line.
*/
static int side(Point const a, Point const b, Point const p)
{
	Fixed const &ax = a.getX();
	Fixed const &ay = a.getY();
	Fixed const &bx = b.getX();
	Fixed const &by = b.getY();
	Fixed const &px = p.getX();
	Fixed const &py = p.getY();

	/* Line AB vector: (bx - ax, by - ay)
	CCW normal vector of line AB: (ay - by, bx - ax)
	Line AP vector: (px - ax, py - ay)
	Positive dot product indicates P is in same half-plane as normal vector */
	Fixed dot = (ay - by) * (px - ax) + (bx - ax) * (py - ay);
	if (dot < 0)
		return -1;
	if (dot > 0)
		return 1;
	return 0;
}

/*
	Determines if point `point` is inside triangle formed by points `a`, `b`, and `c`.

	If a point is exactly on an edge of the triangle (to the limit of numeric accuracy),
	it is not considered to be inside the triangle.
*/
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	/* If point is inside the triangle, it must be on the same side of lines AB, BC, and CA.
	If ABC is counterclockwise, an inside point is on the left side of each line.
	If ABC is clockwise, an inside point is on the right side of each line. */
	int sides = side(a, b, point) + side(b, c, point) + side(c, a, point);
	return (sides == 3) || (sides == -3);
}
