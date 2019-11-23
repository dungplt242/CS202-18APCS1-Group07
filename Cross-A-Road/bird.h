#pragma once
#include "obstacle.h"

class Bird : public Obstacle {
public:
	Bird();
	~Bird();
	std::string type_name();
private:
};
