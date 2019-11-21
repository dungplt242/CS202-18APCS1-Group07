#pragma once

#include "game_level.h"
#include <memory>

class Game_state {
public:

private:
	std::shared_ptr<Game_level> current_level;
};