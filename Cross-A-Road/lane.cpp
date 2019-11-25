#include "lane.h"
#include "random.h"

Lane::Lane(Point upper, Point lower):Window(upper, lower)
{
}

void Lane::do_tick()
{
}

void Lane::render()
{
	destroy_obstacles_outside();
	for (auto obs : obstacles) {
		draw_entity(obs, true); // erase
		obs->move();
		draw_entity(obs);
	}
}

void Lane::generate_obstacles()
{
	if (obstacles.size()) return;
	int type = Random::Int(0, 4);
	int dir_to_right = Random::Int(1, 1);
	Point loca_obs, dir;
	if (dir_to_right) {
		loca_obs = upper_left + Point(1, Random::Int(-10, -4));
		dir = { 0, 1 };
	} else{
		loca_obs = Point(upper_left.x, lower_right.y) + Point(1, Random::Int(0, 1));
		dir = { 0, -1 };
	}
	std::shared_ptr<Obstacle> obs;
	switch (type) {
	case 0: obs = std::make_shared<Car>(loca_obs, dir); break;
	case 1: obs = std::make_shared<Truck>(loca_obs, dir); break;
	case 2: obs = std::make_shared<Bus>(loca_obs, dir); break;
	case 3: obs = std::make_shared<Bird>(loca_obs, dir); break;
	case 4: obs = std::make_shared<Dinosaur>(loca_obs, dir); break;
	}
	obstacles.push_back(obs);
}

void Lane::destroy_obstacles_outside()
{
	for (int i = (int)obstacles.size() - 1; i >= 0; --i) {
		if (!contain(obstacles[i])) {
			obstacles.erase(obstacles.begin() + i);
		}
	}
	for (auto obs : obstacles) {
		
	}
}
