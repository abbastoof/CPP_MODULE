#include "../include/Point.hpp"


/* A utility function to calculate area of triangle formed by (x1, y1), 
(x2, y2) and (x3, y3) */

double	ft_abs(double value)
{
	if (value < 0)
		value = -value;
	return (value);
}

/* Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2 */

double area(Point a, Point b, Point c)
{
	Fixed side1 = a.getX() * (b.getY() - c.getY());
	Fixed side2 = b.getX() * (c.getY() - a.getY());
	Fixed side3 = c.getX() * (a.getY() - b.getY());
	Fixed area = (side1 + side2 + side3) / 2;
	return (ft_abs(area.toFloat()));
}

/* A function to check whether point P(x, y) lies inside the triangle formed
by A(x1, y1), B(x2, y2) and C(x3, y3) */

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	/* Calculate area of triangle ABC */
	double A = area(a, b, c);

	/* Calculate area of triangle PBC */
	double A1 = area(point, b, c);

	/* Calculate area of triangle PAC */
	double A2 = area(a, point, c);

	/* Calculate area of triangle PAB */
	double A3 = area(a, b, point);

	/* Check if the point is on an edge or a vertex */
	if (A1 == 0 || A2 == 0 || A3 == 0)
		return (false);

	/* Check if sum of A1, A2 and A3 is same as A */
	if (A >= A1 + A2 + A3)
		return (true);
	else
		return (false);
}
