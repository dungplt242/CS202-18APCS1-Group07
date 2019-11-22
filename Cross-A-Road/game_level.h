#pragma once

#include "game_map.h"
#include "player.h"
#include <memory>

class Game_level {
public:
	void do_tick();
	void render();
private:
	int level_id = 0;
	Game_map current_map;
	Player player;
};

