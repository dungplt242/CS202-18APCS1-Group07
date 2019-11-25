#pragma once
#include "entity.h"

class Obstacle : public Entity {
public:
	Obstacle();
	Obstacle(Point loca, Point direction = {0, 1});
	virtual std::string type_name() = 0;
	void move();
	bool is_far_enough(int distance);
private:
	void do_tick();
	int tick_passed = 0;
	Point direction;
};

