#pragma once

#include "game_map.h"
#include "player.h"
#include <memory>

class Game_level : public Window {
public:
	Game_level();
	Game_level(int level_id);
	void do_tick();
	void render();
	bool is_finished();
private:
	int level_id = 0;
	bool finished = false;
	std::shared_ptr<Game_map> current_map = nullptr;
	std::shared_ptr<Player> player = nullptr;
};

