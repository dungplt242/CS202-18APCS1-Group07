#pragma once

#include "window.h"
#include "obstacle.h"
#include <vector>
#include <memory>
#include "car.h"
#include "bus.h"
#include "truck.h"
#include "dinosaur.h"
#include "bird.h"

class Lane : public Window {
public:
	Lane(Point upper, Point lower);
	virtual ~Lane();
	void do_tick();
	void render();
	void generate_obstacles();
	void destroy_obstacles_outside();
protected:
	std::vector<std::shared_ptr<Obstacle>> obstacles;
private:
};

