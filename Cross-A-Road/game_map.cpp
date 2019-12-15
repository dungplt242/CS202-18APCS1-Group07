#include "game_map.h"
#include <algorithm>

Game_map::Game_map(Point upper_left, Point lower_right, int n_lanes, int lane_width, int diff) 
	: difficulty(diff), lanes(n_lanes), Window(upper_left, lower_right)
{
	for (int i = 0; i < n_lanes; ++i) {
		lanes[i] = std::make_shared<Lane>(
			Point{ upper_left.x + i * lane_width + 1, upper_left.y + 1 },
			Point{ upper_left.x + (i + 1) * lane_width, lower_right.y - 1 },
			i == 0 || i + 1 == n_lanes
			);

		if (i != 0 && i + 1 != n_lanes) {
			// set lane to generate obstacles if not first or last lane
			lanes[i]->set_cooldown(std::max(20, 50 - diff));
		}
		//lanes[i]->draw_rect('#'); 
	}
	render_box();
}

bool Game_map::is_finished(std::shared_ptr<Player> player)
{
	return lanes.back()->contain(player);
}

void Game_map::init()
{
	for (auto lane : lanes)
		lane->init();
}

void Game_map::update()
{
	for (auto& lane : lanes)
		lane->update();
}

void Game_map::render()
{
	for (auto& lane : lanes)
		lane->render();
}

void Game_map::update_and_render()
{
	for (auto& lane : lanes)
		lane->update_and_render();
}

void Game_map::render_box()
{
	for (int i = 0; i < lanes.size(); ++i) {
		//draw pavement & road marking
		if (i == 1)  lanes[i]->draw_road_marking(true, false);
		else if (i == (int)lanes.size() - 2) lanes[i]->draw_road_marking(false, true);
		else if (i > 1 && i <(int)lanes.size() - 2) lanes[i]->draw_road_marking(false, false);
	}
}

void Game_map::import_from_file(std::ifstream & fi)
{
	int lanes_size;
	fi >> lanes_size;
	lanes.resize(lanes_size);
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
