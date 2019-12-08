#pragma once

#include "window.h"
#include "obstacle.h"
#include <vector>
#include <memory>

class Lane : public Window {
public:
	Lane(Point upper, Point lower);
	virtual ~Lane();
	void do_tick();
	void render();
	void generate_obstacles();
	void destroy_obstacles_outside();
	void export_to_file(std::ofstream& fo);
	void import_from_file(std::ifstream& fi);
protected:
	std::vector<std::shared_ptr<Obstacle>> obstacles;
private:
};

