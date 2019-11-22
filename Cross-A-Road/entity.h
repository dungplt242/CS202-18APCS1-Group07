#pragma once

#include "pixel.h"
#include <vector>

class Entity {
public:
	Entity();
	virtual ~Entity();
	bool collide(const Entity& other);

	friend class Window;
protected:
	Point location = { 0, 0 };
	std::vector<Pixel> pixels;
};