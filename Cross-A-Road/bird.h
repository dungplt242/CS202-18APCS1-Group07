#pragma once
#include "obstacle.h"

class Bird : public Obstacle {
public:
	Bird();
	Bird(Point loca, Point dir);
	~Bird();
	std::string type_name();
	int obs_type();

private:
};
