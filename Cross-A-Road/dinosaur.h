#pragma once
#include "obstacle.h"

class Dinosaur : public Obstacle {
public:
	Dinosaur();
	Dinosaur(Point loca, Point dir);
	~Dinosaur();
	std::string type_name();
	int obs_type();

private:
};