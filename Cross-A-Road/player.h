#pragma once

#include "entity.h"
#include "point.h"

class Player : public Entity {
public:
	void move(Point d);
private:
};

