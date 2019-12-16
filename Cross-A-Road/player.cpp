#include "player.h"
#include <vector>
#include <iostream>
#include "console.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13 
#define ESC 27

Player::Player()
{
	location = { 3, 3 };
	load_icon();
}

Player::~Player()
{
}

std::string Player::type_name()
{
	return "Player";
}

Point Player::get_loca()
{
	return location;
}

void Player::move(Point d)
{
	//Console::MakeSound("Data/Sound/move.wav");
	location = d;
}

void Player::die()
{
	Console::MakeSound("Data/Sound/player_die.wav");
}

void Player::process_input(const char & ch, int lane_width)
{
	switch (ch) {
		case KEY_UP: {
			move({ location.x - lane_width, location.y });
			break;
		}
		case KEY_DOWN: {
			move({ location.x + lane_width, location.y });
			break;
		}
		case KEY_LEFT: {
			move({ location.x, location.y - 3 });
			break;
		}
		case KEY_RIGHT: {
			move({ location.x, location.y + 3 });
			break;
		}
		default:
			break;
	}
}

void Player::export_to_file(std::ofstream & fo)
{
	location.export_to_file(fo);
}

void Player::import_from_file(std::ifstream & fi)
{
	location.import_from_file(fi);
}

