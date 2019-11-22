#pragma once

#define HOUT GetStdHandle(STD_OUTPUT_HANDLE)
#define HIN GetStdHandle(STD_INPUT_HANDLE)

namespace Console
{
	void gotoXY(int x, int y);
	void clear_screen();
	void full_screen();
}
