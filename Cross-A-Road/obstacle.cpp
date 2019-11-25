#include "obstacle.h"

Obstacle::Obstacle()
{
}

Obstacle::Obstacle(Point loca, Point direction):Entity(loca), direction(direction)
{
}

void Obstacle::do_tick()
{
}

void Obstacle::move()
{
	location += direction;
}
