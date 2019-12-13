#pragma once

#include "window.h"

class Lane : public Window {
public:
<<<<<<< Updated upstream

=======
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
	bool is_stop = false;
	int time = 0; // change between stop and non-stop
	bool dir_to_right = true;
>>>>>>> Stashed changes
private:
	void update_time();
	void show_time_and_flag();
	void clear_flag();
};

