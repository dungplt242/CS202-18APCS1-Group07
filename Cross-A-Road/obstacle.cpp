#include "obstacle.h"
#include "car.h"
#include "bird.h"
#include "bus.h"
#include "truck.h"
#include "dinosaur.h"

Obstacle::Obstacle()
{
}

Obstacle::Obstacle(Point loca, Point direction):Entity(loca), direction(direction)
{
}

Obstacle::~Obstacle()
{

}

void Obstacle::do_tick()
{
}

std::shared_ptr<Obstacle> Obstacle::Create(ObstacleType type, Point loca_obs, Point dir)
{
	switch (type) {
	case OT_Car: return std::make_shared<Car>(loca_obs, dir);
	case OT_Bus: return std::make_shared<Bus>(loca_obs, dir);
	case OT_Truck: return std::make_shared<Truck>(loca_obs, dir); 
	case OT_Bird: return std::make_shared<Bird>(loca_obs, dir); 
	case OT_Dinasour: return std::make_shared<Dinosaur>(loca_obs, dir);
	}
	return std::shared_ptr<Obstacle>();
}

void Obstacle::move()
{
	location += direction;
}

bool Obstacle::is_far_enough(int distance)
{
	if (location.y >= distance) return true;
	return false;
}
