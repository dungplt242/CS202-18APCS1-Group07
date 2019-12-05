#include "bird.h"

Bird::Bird()
{
	//location = { };
	load_icon();
}

Bird::Bird(Point loca, Point dir):Obstacle(loca, dir)
{
	load_icon(dir.y == -1);
}

Bird::~Bird()
{
}

std::string Bird::type_name()
{
	return "Bird";
}

int Bird::obs_type()
{
	return 3;
}
