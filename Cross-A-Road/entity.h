#pragma once

#include "window.h"

#include <vector>

class Entity {
public:
	Entity();
	virtual ~Entity();
private:
	std::vector<Point> points;
};

