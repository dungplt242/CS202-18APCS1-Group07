#pragma once

#include "window.h"
#include "obstacle.h"
#include "player.h"
#include <vector>
#include <memory>

class Lane : public Window {
public:
	Lane(Point upper, Point lower);
	virtual ~Lane();
	void init();
	void update_and_render();
	void generate_obstacles();
	void export_to_file(std::ofstream& fo);
	void import_from_file(std::ifstream& fi);
	bool check_collide(std::shared_ptr<Player> player);
	void set_cooldown(int x);
protected:
	std::vector<std::shared_ptr<Obstacle>> obstacles;
	int tick_passed = 0;
	int cooldown = 0;		// time between consecutive obstacle generation
	bool is_stop = false;
	int traffic_time = 0; // change between stop and non-stop
	bool dir_to_right;
private:
	void update_traffic_lights();
	void show_time_and_flag();
	void clear_flag();
};

