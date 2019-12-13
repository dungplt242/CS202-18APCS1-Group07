#include "console.h"
#include <Windows.h>

namespace Console {
	void gotoXY(int x, int y) {
		COORD pos = { y, x };
		SetConsoleCursorPosition(HOUT, pos);
	}
	void clear_screen()
	{
		system("cls");
	}
	void full_screen()
	{
		SetConsoleDisplayMode(HOUT, CONSOLE_FULLSCREEN_MODE, 0);
	}
}