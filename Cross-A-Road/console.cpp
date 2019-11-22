#include "console.h"
#include <Windows.h>

namespace Console {
	void gotoXY(int x, int y) {
		COORD pos = { y, x };
		SetConsoleCursorPosition(HOUT, pos);
	}
}