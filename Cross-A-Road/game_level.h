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
	std::shared_ptr<Game_map> current_map = nullptr;
	std::shared_ptr<Player> player = nullptr;
};

