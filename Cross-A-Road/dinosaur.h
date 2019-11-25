#pragma once
#include "obstacle.h"

class Dinosaur : public Obstacle {
public:
	Dinosaur();
	~Dinosaur();
	std::string type_name();
private:
};