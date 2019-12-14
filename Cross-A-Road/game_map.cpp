#include "game_map.h"

Game_map::Game_map()
{
}

Game_map::Game_map(Point upper_left, Point lower_right, int n_lanes, int lane_width):lanes(n_lanes), Window(upper_left, lower_right)
{
	for (int i = 0; i < n_lanes; ++i) {
		lanes[i] = std::make_unique<Lane>(
			Point{ upper_left.x + i * lane_width + 1, upper_left.y + 1}, 
			Point{ upper_left.x + (i + 1) * lane_width, lower_right.y - 1});
		//lanes[i]->draw_rect('#'); 

		//draw pavement & road marking
		if (i==1)  lanes[i]->draw_road_marking(true, false);
		else if (i == n_lanes - 2) lanes[i]->draw_road_marking(false, true);
		else if (i > 1 && i < n_lanes - 2) lanes[i]->draw_road_marking(false, false);
	}
}

bool Game_map::is_finished(std::shared_ptr<Player> player)
{
	return lanes.back()->contain(player);
}

void Game_map::update_and_render()
{
	for (int i = 1; i < (int)lanes.size() - 1; ++i) {
		lanes[i]->generate_obstacles();
	}
	for (int i = 0; i < (int)lanes.size(); ++i) {
		lanes[i]->update_and_render();
	}
}

void Game_map::import_from_file(std::ifstream & fi)
{
	int lanes_size;
	fi >> lanes_size;
	lanes.reserve(lanes_size);
	for (int i = 0; i < lanes_size; ++i)
		lanes[i]->import_from_file(fi);
}

void Game_map::export_to_file(std::ofstream & fo)
{
	fo << lanes.size() << std::endl;
	for (int i = 0; i < (int)lanes.size(); ++i)
		lanes[i]->export_to_file(fo);
}

bool Game_map::check_collide(std::shared_ptr<Player> player)
{
	for (int i = 0; i < lanes.size(); i++)
		if (lanes[i]->contain(player)) {
			if (lanes[i]->check_collide(player))
				return true;
			return false;
		}
}
