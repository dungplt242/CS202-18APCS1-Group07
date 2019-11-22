#pragma once

#include "entity.h"
#include "point.h"

class Player : public Entity {
public:
	Player();
	~Player();
	void move(Point d);

private:
};

