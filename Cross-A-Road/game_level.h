#pragma once

#include "game_map.h"
#include "player.h"
#include <memory>

class Game_level : public Window {
public:
	void do_tick();
	void render();
private:
	int level_id = 0;
	Game_map current_map;
	std::shared_ptr<Player> player;
};

