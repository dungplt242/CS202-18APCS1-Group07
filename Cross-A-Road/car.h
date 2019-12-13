#pragma once
#include "obstacle.h"

class Car : public Obstacle {
public:
	Car();
	Car(Point loca, Point dir);
	~Car();
	std::string type_name();
	int obs_type();
private:
};