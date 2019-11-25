#pragma once
#include "obstacle.h"

class Bus : public Obstacle {
public:
	Bus();
	Bus(Point loca, Point dir);
	~Bus();
	std::string type_name();
private:
};