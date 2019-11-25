#include "car.h"

Car::Car()
{
	//location = { };
	load_icon();
}

Car::Car(Point loca, Point dir):Obstacle(loca, dir)
{
	load_icon(dir.y == -1);
}

Car::~Car()
{
}

std::string Car::type_name()
{
	return "Car";
}
