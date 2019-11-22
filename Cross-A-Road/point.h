#pragma once

struct Point {
	int x, y;
	Point& operator+=(const Point& q);
	Point operator+(const Point& q);
};

