#pragma once

#include "lane.h"
#include <memory>
#include <vector>
#include "player.h"

class Game_map : public Window {
public:
	Game_map();
	Game_map(Point upper_left, Point lower_right, int n_lanes, int lane_width);
	void do_tick();
	bool is_finished(std::shared_ptr<Player> player);
	void render();
private:
	std::vector<std::unique_ptr<Lane>> lanes;
};

