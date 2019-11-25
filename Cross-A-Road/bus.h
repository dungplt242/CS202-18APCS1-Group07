#pragma once
#include "obstacle.h"

class Bus : public Obstacle {
public:
	Bus();
	~Bus();
	std::string type_name();
private:
};