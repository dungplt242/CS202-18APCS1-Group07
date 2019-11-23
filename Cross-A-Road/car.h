#pragma once
#include "obstacle.h"

class Car : public Obstacle {
public:
	Car();
	~Car();
	std::string type_name();
private:
};