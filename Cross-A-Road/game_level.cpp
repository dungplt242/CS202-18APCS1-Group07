#include "game_level.h"
#include <iostream>
#include <thread>

Game_level::Game_level(int level_id):level_id(level_id)
{
	int n_lanes = 7, lane_width = 6; // do we need to change each level?
	player = std::make_shared<Player>();
	set_pos({ 1, 1 }, { 44, 150 });
	current_map = std::make_shared<Game_map>(upper_left, lower_right, n_lanes, lane_width);
}

Game_level::~Game_level()
{
	draw_entity(player, true);	// delete player when leveling up
}

void Game_level::update_and_render()
{
	draw_entity(player);
	current_map->update_and_render();
}

bool Game_level::is_finished()
{
	return current_map->is_finished(player);
}

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

int Game_level::get_level_id()
{
	return level_id;
}

void Game_level::import_from_file(std::ifstream &fi)
{
	fi >> level_id;
	player->import_from_file(fi);
	current_map->import_from_file(fi);
}

void Game_level::export_to_file(std::ofstream& fo)
{
	fo << level_id << std::endl;
	player->export_to_file(fo);
	current_map->export_to_file(fo);
}
