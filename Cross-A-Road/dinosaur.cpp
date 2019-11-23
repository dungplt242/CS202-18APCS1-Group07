#include "dinosaur.h"

Dinosaur::Dinosaur()
{
	//location = { };
	load_icon();
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
