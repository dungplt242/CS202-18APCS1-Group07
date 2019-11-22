#include "player.h"
#include <vector>
#include <iostream>

Player::Player()
{
	location = { 2, 3 };
	load_icon();
}

Player::~Player()
{
}

std::string Player::type_name()
{
	return "Player";
}

void Player::move(Point d)
{

}
