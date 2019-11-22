#include "player.h"
#include <vector>
#include <iostream>

Player::Player()
{
	pixels.push_back({ {0, 0}, 'p', 0 });
	pixels.push_back({ {0, 1}, 'p', 0 });
	location = { 2, 2 };
}

Player::~Player()
{
}

void Player::move(Point d)
{

}
