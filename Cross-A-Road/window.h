#pragma once

#include "point.h"

class Window {
public:
	Window();
	virtual ~Window();
private:
	Point upper_left, lower_right;
};