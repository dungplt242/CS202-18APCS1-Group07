#include "lane.h"
#include "random.h"

#include<string>

Lane::Lane(Point upper, Point lower):Window(upper, lower)
{
	dir_to_right = Random::Int(0, 1);
}

Lane::~Lane()
{
	for (auto obs : obstacles) {
		draw_entity(obs, true); // erase
	}
}

void Lane::update_and_render()
{
	update_time();
	if (is_stop) {
		return;
	}
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

void Lane::generate_obstacles()
{
	//if (obstacles.size()) return; //1 obs only
	int type = Random::Int(0, 4);
	Point loca_obs, dir;
	if (dir_to_right) {
		loca_obs = upper_left + Point(1, Random::Int(-20, -8));
		dir = { 0, 1 };
	} else{
		loca_obs = Point(upper_left.x, lower_right.y) + Point(1, Random::Int(-2, 0));
		dir = { 0, -1 };
	}
	int dis = 30; //depends on level
	if (obstacles.size() && !obstacles.back()->is_far_enough(loca_obs, dis))
		return;
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
void Lane::update_time()
{
	--time;
	if (time <= 0) {
		is_stop ^= 1;
		clear_flag();
		time = Random::Int(40, 100);
	}
	show_time_and_flag();
}

void Lane::show_time_and_flag()
{
	Console::gotoXY(upper_left.x + 1, lower_right.y + 4);
	if (is_stop) {
		std::cout << "Red: " << time;
	}
	else std::cout << "Green: " << time;
}

void Lane::clear_flag()
{
	Console::gotoXY(upper_left.x + 1, lower_right.y + 4);
	for (int i = 0; i < 10; ++i) std::cout << ' ';
}
