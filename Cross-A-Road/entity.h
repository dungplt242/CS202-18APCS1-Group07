#pragma once

#include "pixel.h"
#include <vector>

class Entity {
public:
	Entity();
	virtual ~Entity();
	bool collide(const Entity& other);
	virtual void load_icon();
	virtual std::string type_name() = 0;
	friend class Window;
protected:
	Point location = { 0, 0 };
	std::vector<Pixel> pixels;
};