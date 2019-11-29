#pragma once

#include "window.h"
#include "obstacle.h"
#include <vector>
#include <memory>

class Lane : public Window {
public:
	Lane(Point upper, Point lower);
	void do_tick();
	void render();
	void generate_obstacles();
	void destroy_obstacles_outside();
protected:
	std::vector<std::shared_ptr<Obstacle>> obstacles;
private:
};

