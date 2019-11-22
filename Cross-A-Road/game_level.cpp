#include "game_level.h"
#include <iostream>

void Game_level::do_tick()
{
}

void Game_level::render()
{
	player = std::make_shared<Player>();
	set_pos({ 1, 1 }, { 30, 80 });
	draw_entity(player);
}
