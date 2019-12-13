#include "lane.h"
#include "random.h"

#include<string>

Lane::Lane(Point upper, Point lower):Window(upper, lower)
{
}

Lane::~Lane()
{
	for (auto obs : obstacles) {
		draw_entity(obs, true); // erase
	}
}

void Lane::update_and_render()
{
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
	int dis = 20; //depends on level
	if (obstacles.size() && !obstacles.back()->is_far_enough(upper_left.y + dis))
		return;
	int type = Random::Int(0, 4);
	int dir_to_right = Random::Int(1, 1);
	Point loca_obs, dir;
	if (dir_to_right) {
		loca_obs = upper_left + Point(1, Random::Int(-20, -8));
		dir = { 0, 1 };
	} else{
		loca_obs = Point(upper_left.x, lower_right.y) + Point(1, Random::Int(0, 1));
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
