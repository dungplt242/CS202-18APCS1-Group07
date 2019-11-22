#pragma once

#include "lane.h"
#include <memory>
#include <vector>

class Game_map {
public:
	void do_tick();
	void render();
private:
	std::vector<std::unique_ptr<Lane>> lanes;
};

