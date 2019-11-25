#pragma once
#include "obstacle.h"

class Truck : public Obstacle {
public:
	Truck();
	~Truck();
	std::string type_name();
private:
};