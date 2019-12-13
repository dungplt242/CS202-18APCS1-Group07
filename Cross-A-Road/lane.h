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
	bool is_stop = false;
	int time = 0; // change between stop and non-stop
	bool dir_to_right = true;
private:
	void update_time();
	void show_time_and_flag();
	void clear_flag();
};

