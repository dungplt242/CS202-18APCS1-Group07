#pragma once

#include "pixel.h"
#include <vector>
#include <string>

class Entity {
public:
	Entity();
	Entity(Point loca);
	virtual ~Entity();
	bool collide(const Entity& other);
	virtual void load_icon(bool isFlipped = false);
	virtual std::string type_name() = 0;
	friend class Window;
protected:
	Point location = { 0, 0 };
	std::vector<Pixel> pixels;
};