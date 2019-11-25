#include "truck.h"

Truck::Truck()
{
	//location = { };
	load_icon();
}

Truck::~Truck()
{
}

std::string Truck::type_name()
{
	return "Truck";
}
