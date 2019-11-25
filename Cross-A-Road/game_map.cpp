#include "game_map.h"

Game_map::Game_map(Point upper_left, Point lower_right, int n_lanes, int lane_width):lanes(n_lanes), Window(upper_left, lower_right)
{
	for (int i = 0; i < n_lanes; ++i) {
		lanes[i] = std::make_unique<Lane>(
			Point{ upper_left.x + i * lane_width + 1, upper_left.y + 1}, 
			Point{ upper_left.x + (i + 1) * lane_width, lower_right.y - 1});
		lanes[i]->draw_rect('#');
	}
}

void Game_map::do_tick()
{
}

void Game_map::render()
{
	for (int i = 1; i < (int)lanes.size() - 1; ++i) {
		lanes[i]->generate_obstacles();
	}
	for (int i = 0; i < (int)lanes.size(); ++i) {
		lanes[i]->render();
	}
}
