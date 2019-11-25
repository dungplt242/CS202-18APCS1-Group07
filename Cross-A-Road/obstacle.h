#pragma once
#include "entity.h"
class Obstacle : public Entity {
public:
	virtual std::string type_name() = 0;

private:
	void do_tick();

	int tick_passed = 0;
};

