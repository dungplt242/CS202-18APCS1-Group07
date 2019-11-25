#include "bird.h"

Bird::Bird()
{
	//location = { };
	load_icon();
}

Bird::~Bird()
{
}

std::string Bird::type_name()
{
	return "Bird";
}
