#include "lane.h"
#include "random.h"

#include <string>

Lane::Lane(Point upper, Point lower, bool is_special) : Window(upper, lower), is_special(is_special)
{
	dir_to_right = Random::Int(0, 1);
}

Lane::~Lane()
{
	for (auto obs : obstacles) {
		draw_entity(obs, true); // erase
	}
	if (!is_special) unrender_traffic_light();
}

void Lane::init()
{
	for (int i = 0; i < 300; ++i) 
		update();
}

void Lane::update()
{
	if (is_special) return;

	if (is_rendered) 
		unrender_traffic_light();

	update_traffic_lights();
	
	if (!is_stop) {
		// note that time when the lights are red is not counted towards
		// obstacle generation

		for (auto obs : obstacles) 
			if (is_rendered) draw_entity(obs, true);	// erase

		++tick_passed;

		if (cooldown && tick_passed % cooldown == 0) {
			generate_obstacles();
		}

		// delete obstacles that go out of the window
		std::vector<std::shared_ptr<Obstacle> > obs_new;
		for (auto obs : obstacles) {
			obs->do_tick();
			if (contain(obs)) {
				obs_new.push_back(obs);
			}
		}
		obstacles.swap(obs_new);
	}
	is_rendered = false;
}

void Lane::render()
{
	if (is_special || is_rendered) return;
	
	render_traffic_light();
	for (auto obs : obstacles) 
		if (contain(obs)) {
			draw_entity(obs);
		}

	is_rendered = true;
}

void Lane::update_and_render()
{
	if (is_special) return;

	unrender_traffic_light();
	update_traffic_lights();
	render_traffic_light();
	if (!is_stop) {
		// note that time when the lights are red is not counted towards
		// obstacle generation

		++tick_passed;

		if (cooldown && tick_passed % cooldown == 0) {
			generate_obstacles();
		}

		// delete obstacles that go out of the window
		std::vector<std::shared_ptr<Obstacle> > obs_new;
		for (auto obs : obstacles) {
			draw_entity(obs, true);		// optimization: does not check if not rendered
			obs->do_tick();
			if (contain(obs)) {
				draw_entity(obs);
				obs_new.push_back(obs);
			}
		}
		obstacles.swap(obs_new);
	}
	is_rendered = true;
}

void Lane::generate_obstacles()
{
	int type = Random::Int(0, 4);
	Point loca_obs, dir;
	if (dir_to_right) {
		loca_obs = upper_left + Point(1, Random::Int(-10, -7));			// negative offset to make sure obstacles don't "jump" out
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
	fo << obstacles.size() << std::endl;
	for (int i = 0; i < (int)obstacles.size(); ++i)
		obstacles[i]->export_to_file(fo);
}

void Lane::import_from_file(std::ifstream & fi)
{
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
		if (obstacles[i]->collide(player))
			return true;
	return false;
}

void Lane::set_cooldown(int x)
{
	cooldown = x;
}

void Lane::update_traffic_lights()
{
	--traffic_time;
	if (traffic_time <= 0) {
		is_stop ^= 1;
		traffic_time = Random::Int(40, 100);
	}
}

void Lane::render_traffic_light()
{
	Console::gotoXY(upper_left.x + 1, lower_right.y + 4);
	if (is_stop) {
		Console::SetColor(COLOR::RED);
	}
	else Console::SetColor(COLOR::GREEN);
	putchar(char(219));
	putchar(' ');
	putchar('0' + traffic_time / 10);
	Console::SetColor(COLOR::WHITE);
}

void Lane::unrender_traffic_light()
{
	Console::gotoXY(upper_left.x + 1, lower_right.y + 4);
	for (int i = 0; i < 4; ++i) putchar(' ');
}
