#include "entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::draw()
{
	for (auto pixel : pixels) {
		//
	}
}

bool Entity::collide(const Entity& other)
{
	return false;
}
