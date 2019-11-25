#include "game_level.h"
#include <iostream>

void Game_level::do_tick()
{
}

void Game_level::render()
{
	if (player == nullptr) player = std::make_shared<Player>();
	if (current_map == nullptr) {
		int n_lanes = 7, lane_width = 6; // Do we need to edit it each level??
		set_pos({ 1, 1 }, { 44, 150 });
		current_map = std::make_shared<Game_map>(upper_left, lower_right, n_lanes, lane_width);
	}
	draw_entity(player);
	current_map->render();
}
