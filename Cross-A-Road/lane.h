#pragma once

#include "window.h"
#include "obstacle.h"
#include <vector>
#include <memory>

class Lane : public Window {
public:
	Lane(Point upper, Point lower);
	virtual ~Lane();
	void update_and_render();
	void generate_obstacles();
	void export_to_file(std::ofstream& fo);
	void import_from_file(std::ifstream& fi);
protected:
	std::vector<std::shared_ptr<Obstacle>> obstacles;
private:
};

