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
protected:
	std::vector<std::unique_ptr<Obstacle>> obstacles;
private:
};

