#pragma once
#include <iostream>
#include "point.h"
#include "console.h"
#include "entity.h"

class Window {
public:
	Window();
	Window(Point upper, Point lower);
	virtual ~Window();

	void turn_on_reverse_color();
	void turn_off_reverse_color();

	bool contain(Point x);
	void draw_full_rect(char c = '*');
	void draw_rect(char c = '*');
	void draw_entity(std::shared_ptr<Entity> entity);

	void print_center_align(std::string st, int line);
	
	void set_pos(Point upper, Point lower);
	
protected:
	Point upper_left, lower_right;

};
