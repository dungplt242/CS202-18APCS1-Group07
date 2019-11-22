#pragma once
#include "window.h"
#include <vector>
#include <conio.h>

enum MENU_NAME{
	NEW_GAME,
	LOAD_GAME,
	SAVE_GAME,
	SETTINGS,
	QUIT
};

class Menu : public Window {
public:
	Menu();
	virtual ~Menu();

	void load_menu();
	int get_input();
private:
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
	void Unchoose(int id);
	void Choose(int id);
};

