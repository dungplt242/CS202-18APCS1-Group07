#pragma once

#include "game_state.h"
#include "menu.h"

#include <memory>

class Game_module {
public:
	void show_main();
private:
	void do_menu_choice();
	void start_game(std::shared_ptr<Game_state> start_state = std::make_shared<Game_state>());
	void load_game(std::shared_ptr<Game_state> state);
	void save_game();
	Menu menu;
	std::shared_ptr<Game_state> current_state;
};