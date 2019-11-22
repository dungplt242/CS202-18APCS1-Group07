#pragma once
#include "entity.h"
class Obstacle : public Entity {
public:

private:
	void do_tick();

	int tick_passed;
};

