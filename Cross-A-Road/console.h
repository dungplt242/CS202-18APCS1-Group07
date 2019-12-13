#pragma once

#define HOUT GetStdHandle(STD_OUTPUT_HANDLE)
#define HIN GetStdHandle(STD_INPUT_HANDLE)
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13 
#define ESC 27

namespace Console
{
	void gotoXY(int x, int y);
	void clear_screen();
	void full_screen();
}
