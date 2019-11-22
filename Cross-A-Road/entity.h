#pragma once

#include "pixel.h"

#include <vector>

class Entity {
public:
	Entity();
	virtual ~Entity();
	void draw();
	bool collide(const Entity& other);
protected:
	Point location = { 0, 0 };
	std::vector<Pixel> pixels;
};