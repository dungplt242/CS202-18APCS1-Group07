#pragma once

#include "game_state.h"
#include "menu.h"

#include <memory>

class Game_module {
public:
	void show_main();
	void load_game(std::shared_ptr<Game_state> state);
	void start_game(std::shared_ptr<Game_state> start_state = std::make_shared<Game_state>());
private:
	void start_game(std::shared_ptr<Game_state> start_state = std::make_shared<Game_state>());
	void load_game(std::shared_ptr<Game_state> state);
	void save_game();
	Menu menu;
	Game_state current_state;
};