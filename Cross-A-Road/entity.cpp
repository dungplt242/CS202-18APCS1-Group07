#include "entity.h"
#include "console.h"
#include <iostream>

using Console::gotoXY;

Entity::Entity()
{
}


Entity::~Entity()
{
}


bool Entity::collide(const Entity& other)
{
	return false;
}
