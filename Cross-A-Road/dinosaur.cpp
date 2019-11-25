#include "dinosaur.h"

Dinosaur::Dinosaur()
{
	//location = { };
	load_icon();
}

Dinosaur::Dinosaur(Point loca, Point dir):Obstacle(loca, dir)
{
	load_icon(dir.y == -1);
}

Dinosaur::~Dinosaur()
{
	//location = { };
	load_icon();
}

std::string Dinosaur::type_name()
{
	return "Dinosaur";
}
