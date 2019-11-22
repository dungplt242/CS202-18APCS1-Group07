#pragma once
#include "window.h"
#include <vector>
#include <conio.h>

class Menu : public Window {
public:
	Menu();
	virtual ~Menu();

	void load_menu();
	int get_input();
private:
	enum {
		NEW_GAME,
		LOAD_GAME,
		SAVE_GAME,
		SETTINGS,
		QUIT
	};
	std::vector<std::string> content = {
		"NEW GAME",
		"LOAD GAME",
		"SAVE GAME",
		"SETTINGS",
		"QUIT"
	};
	Point start_point;
	int max_length; // max length of content menu
	int cursor;
	std::vector<Window> rect; // contain rect of content i
	void update_cursor(int id); // turn off/on cursor
	void Unchoose(int id);
	void Choose(int id);
};

