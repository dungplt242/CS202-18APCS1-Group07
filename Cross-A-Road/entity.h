#pragma once

#include "pixel.h"

#include <vector>

class Entity {
public:
	Entity();
	virtual ~Entity();
	void draw();
private:
	Point location;
	std::vector<Pixel> pixels;
};

