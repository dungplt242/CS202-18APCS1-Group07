#include "bus.h"

Bus::Bus()
{
	//location = { };
	load_icon();
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
