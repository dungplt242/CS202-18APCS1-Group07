#pragma once
#include "obstacle.h"

class Truck : public Obstacle {
public:
	Truck();
	Truck(Point loca, Point dir);
	~Truck();
	std::string type_name();
	int obs_type();

private:
};