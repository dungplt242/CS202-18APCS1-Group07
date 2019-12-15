#include "lane.h"
#include "random.h"

#include<string>

Lane::Lane(Point upper, Point lower, bool is_special) : Window(upper, lower), is_special(is_special)
{
	dir_to_right = Random::Int(0, 1);
}

Lane::~Lane()
{
	for (auto obs : obstacles) {
		draw_entity(obs, true); // erase
	}
	if (!is_special) clear_flag();
}

void Lane::init()
{
	traffic_time = 180 + Random::Int(0, 40);
	for (int i = 0; i < 200; ++i)
		update_and_render();

}

void Lane::update_and_render()
{
	if (is_special) return;
	update_traffic_lights();
	if (is_stop) {
		return;
	}

	// note that time when the lights are red is not counted towards
	// obstacle generation

	++tick_passed;

	if (cooldown && tick_passed % cooldown == 0) {
		generate_obstacles();
	}

	// delete obstacles that go out of the window
	std::vector<std::shared_ptr<Obstacle> > obs_new;
	for (auto obs : obstacles) {
		draw_entity(obs, true);	// erase
		obs->do_tick();
		if (contain(obs)) {
			obs_new.push_back(obs);
			draw_entity(obs);
		}
	}
	obstacles.swap(obs_new);
}

void Lane::render_only()
{
	if (is_special) return;
	update_traffic_lights();
	for (auto obs : obstacles) {
		draw_entity(obs);
	}
}

void Lane::generate_obstacles()
{
	int type = Random::Int(0, 4);
	Point loca_obs, dir;
	if (dir_to_right) {
		loca_obs = upper_left + Point(1, Random::Int(-0, -0));
		dir = { 0, 1 };
	} else{
		loca_obs = Point(upper_left.x, lower_right.y) + Point(1, Random::Int(-2, 0));
		dir = { 0, -1 };
	}
	std::shared_ptr<Obstacle> obs = Obstacle::Create(static_cast<ObstacleType>(type), loca_obs, dir);
	obstacles.push_back(obs);
}


void Lane::export_to_file(std::ofstream & fo)
{
	fo << dir_to_right << '\n';
	fo << obstacles.size() << std::endl;
	for (int i = 0; i < (int)obstacles.size(); ++i)
		obstacles[i]->export_to_file(fo);
}

void Lane::import_from_file(std::ifstream & fi)
{
	fi >> dir_to_right;
	int obstacles_size;
	fi >> obstacles_size;
	obstacles.reserve(obstacles_size);
	for (int i = 0; i < obstacles_size; ++i) {
		std::shared_ptr<Obstacle> obs = Obstacle::obs_import_from_file(fi);
		obstacles.push_back(obs);
	}
}
bool Lane::check_collide(std::shared_ptr<Player> player)
{
	for (int i = 0; i < obstacles.size(); i++)
		if (obstacles[i]->collide(player)) {
			player->die();
			// Make sound of obstacles
			return true;
		}
	return false;
}

void Lane::set_cooldown(int x)
{
	cooldown = x;
}

void Lane::update_traffic_lights()
{
	--traffic_time;
	clear_flag();
	if (traffic_time <= 0) {
		is_stop ^= 1;
		traffic_time = Random::Int(40, 80) + is_stop * 20;
	}
	show_time_and_flag();
}

void Lane::show_time_and_flag()
{
	Console::gotoXY(upper_left.x + 1, lower_right.y + 4);
	if (is_stop) {
		Console::SetColor(COLOR::RED);
	}
	else Console::SetColor(COLOR::GREEN);
	std::cout << char(219) << ' ' << traffic_time / 10;
	Console::SetColor(COLOR::WHITE);
}

void Lane::clear_flag()
{
	Console::gotoXY(upper_left.x + 1, lower_right.y + 4);
	for (int i = 0; i < 10; ++i) std::cout << ' ';
}
