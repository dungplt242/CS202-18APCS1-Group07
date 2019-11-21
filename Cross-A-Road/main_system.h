#pragma once

#include "game_state.h"
#include <memory>

class Game_module {
public:
	void start_game(std::shared_ptr<Game_state> start_state = std::make_shared<Game_state>());
private:
	
};