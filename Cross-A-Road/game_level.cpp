#include "game_level.h"
#include <iostream>
#include <thread>


void Game_level::do_tick()
{
}

void Game_level::render()
{
	int n_lanes = 7, lane_width = 6; // for player loop
	if (player == nullptr) player = std::make_shared<Player>();
	if (current_map == nullptr) {
		n_lanes = 7, lane_width = 6; // Do we need to edit it each level??
		set_pos({ 1, 1 }, { 44, 150 });
		current_map = std::make_shared<Game_map>(upper_left, lower_right, n_lanes, lane_width);
	}
	draw_entity(player);
	current_map->render();
}

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void Game_level::process_input(const char & ch)
{
	if (ch == KEY_DOWN || ch == KEY_UP || ch == KEY_LEFT || ch == KEY_RIGHT) {
		draw_entity(player, true);
		Point prev_loca = player->get_loca();
		player->process_input(ch, 6); //6: lane_width
		if (!contain(player))
			player->move(prev_loca);
	}
		
}
