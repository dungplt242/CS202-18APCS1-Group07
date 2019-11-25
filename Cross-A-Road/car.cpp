#include "car.h"

Car::Car()
{
	//location = { };
	load_icon();
}

Car::~Car()
{
}

std::string Car::type_name()
{
	return "Car";
}
