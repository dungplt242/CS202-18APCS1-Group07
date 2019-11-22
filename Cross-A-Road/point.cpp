#include "point.h"


Point& Point::operator+=(const Point& q)
{
	x += q.x;
	y += q.y;
	return *this;
}

Point Point::operator+(const Point& q)
{
	Point p(*this);
	p += q;
	return p;
}