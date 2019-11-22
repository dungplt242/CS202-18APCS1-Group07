#include "menu.h"
#include <algorithm>
#include <iostream>

Menu::Menu()
{
}


Menu::~Menu()
{
}


void Menu::load_menu()
{
	draw_rect();
	max_length = 0;
	rect.resize(content.size());
	for (int i = NEW_GAME; i <= QUIT; ++i) max_length = std::max(max_length, (int)content[i].size());
	for (int i = NEW_GAME; i <= QUIT; ++i) {
		Point current_point = { (lower_right.x + upper_left.x) / 2 - (int)content.size() + i * 2, (lower_right.y + upper_left.y - max_length) / 2};
		rect[i].set_pos(current_point + Point(-1, -2), current_point + Point(1, max_length + 1));
		rect[i].draw_rect('-');
		print_center_align(content[i], current_point.x);
	}
	cursor = NEW_GAME;
}

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13 
#define ESC 27

int Menu::get_input()
{
	while (true) {
		Choose(cursor);
		while (!_kbhit());
		//

		//
		char c = _getch();
		while (c == 0 || c == 224) c = _getch();
		Unchoose(cursor);
		switch (c) {
		case KEY_UP: {
			cursor = (cursor - 1 + content.size()) % content.size();
			break;
		}
		case KEY_DOWN: {
			cursor = (cursor + 1) % content.size();
			break;
		}
		case ENTER:
			return cursor;
		case ESC:
			exit(0);
			return -1;
		}
	}
}

void Menu::Unchoose(int id) {
	turn_off_reverse_color();
	rect[id].draw_full_rect(' ');
	int line = (lower_right.x + upper_left.x) / 2 - content.size() + id * 2;
	print_center_align(content[id], line);
	rect[id].draw_rect('-');
}

void Menu::Choose(int id) {
	turn_on_reverse_color();
	rect[id].draw_full_rect(' ');
	int line = (lower_right.x + upper_left.x) / 2 - content.size() + id * 2;
	print_center_align(content[id], line);
	turn_off_reverse_color();
	rect[id].draw_rect('-');
}

