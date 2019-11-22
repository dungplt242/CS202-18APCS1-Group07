#pragma once

#include "point.h"

struct Pixel : Point {
	Pixel operator+(const Point& q);
	int color;
};



