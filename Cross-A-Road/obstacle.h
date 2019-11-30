#pragma once
#include "entity.h"
#include <memory>

enum ObstacleType {
	OT_Car, OT_Bus, OT_Truck, OT_Bird, OT_Dinasour
};
class Obstacle : public Entity {
public:
	Obstacle();
	Obstacle(Point loca, Point direction = {0, 1});
	virtual ~Obstacle();
	virtual std::string type_name() = 0;
	static std::shared_ptr<Obstacle> Create(ObstacleType type, Point loca_obs, Point dir);
	void move();
	bool is_far_enough(int distance);
private:
	void do_tick();
	int tick_passed = 0;
	Point direction;
};

