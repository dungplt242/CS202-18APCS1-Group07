#pragma once

#include "game_map.h"
#include "player.h"
#include <memory>

class Game_level {
public:

private:
	int level_id;
	std::shared_ptr<Game_map> current_map;
	Player player;
};

