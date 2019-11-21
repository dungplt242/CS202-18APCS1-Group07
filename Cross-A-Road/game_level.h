#pragma once

#include "game_map.h"
#include "player.h"
#include <memory>

class Game_level {
public:

private:
	int level_id;
	Game_map current_map;
	Player player;
};

