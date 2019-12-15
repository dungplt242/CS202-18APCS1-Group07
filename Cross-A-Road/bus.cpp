#include "bus.h"

Bus::Bus()
{
	//location = { };
	load_icon();
}

Bus::Bus(Point loca, Point dir):Obstacle(loca, dir)
{
	load_icon(dir.y == -1);
}

Bus::Bus(Point loca, Point direction, int tick_passed) : Obstacle(loca, direction, tick_passed)
{
}

Bus::~Bus()
{
	//location = { };
	load_icon();
}

std::string Bus::type_name()
{
	return "Bus";
}

int Bus::obs_type()
{
	return 1;
}
