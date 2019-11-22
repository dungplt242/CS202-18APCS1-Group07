#pragma once

#include "game_state.h"
#include "menu.h"

#include <memory>

class Game_module {
public:
<<<<<<< Updated upstream
=======
	void show_main();
private:
	Menu menu;
	void load_game(std::shared_ptr<Game_state> state);
>>>>>>> Stashed changes
	void start_game(std::shared_ptr<Game_state> start_state = std::make_shared<Game_state>());
private:
	
};