#pragma once

#include "entity.h"
#include "point.h"

class Player : public Entity {
public:
	Player();
	~Player();
	std::string type_name();
	void move(Point d);
private:
};

