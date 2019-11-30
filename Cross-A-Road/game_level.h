#pragma once

#include "game_map.h"
#include "player.h"
#include <memory>

class Game_level : public Window {
public:
	Game_level(int level_id = 1);
	void do_tick();
	void render();
	bool is_finished(); 
	void process_input(const char &ch);
	int get_level_id();
private:
	int level_id = 0;
	std::shared_ptr<Game_map> current_map = nullptr;
	std::shared_ptr<Player> player = nullptr;
};

