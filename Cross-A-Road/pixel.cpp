#include "pixel.h"

Pixel Pixel::operator+(const Point& q)
{
	Pixel p(*this);
	p += q;
	return p;
}