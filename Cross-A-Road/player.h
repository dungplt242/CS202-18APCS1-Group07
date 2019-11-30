#pragma once

#include "entity.h"
#include "point.h"

enum Direction {
	UP,
	DOWN,
	RIGHT,
	LEFT
};

class Player : public Entity {
public:
	Player();
	~Player();
	std::string type_name();
	Point get_loca();
	void move(Point d);
	void process_input(const char &ch, int lanes_width);
private:
};

