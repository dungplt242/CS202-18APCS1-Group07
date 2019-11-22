#include "window.h"
#include <iostream>
#include <Windows.h>


#define HOUT GetStdHandle(STD_OUTPUT_HANDLE)
#define HIN GetStdHandle(STD_INPUT_HANDLE)

Window::Window()
{
	// set cursor off
	CONSOLE_CURSOR_INFO lpCursor;
	GetConsoleCursorInfo(HOUT, &lpCursor);
	lpCursor.bVisible = 0;
	SetConsoleCursorInfo(HOUT, &lpCursor);
}

Window::Window(Point upper, Point lower):upper_left(upper), lower_right(lower)
{
}


Window::~Window()
{
}

void Window::turn_on_reverse_color()
{
	SetConsoleTextAttribute(HOUT, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}


void Window::turn_off_reverse_color()
{
	SetConsoleTextAttribute(HOUT, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

void Window::gotoXY(int x, int y)
{
	COORD pos = { y, x };
	SetConsoleCursorPosition(HOUT, pos);
}

void Window::draw_full_rect(char c)
{
	for (int x = upper_left.x; x <= lower_right.x; ++x) {
		gotoXY(x, upper_left.y);
		for (int y = upper_left.y; y <= lower_right.y; ++y) std::cout << c;
	}
}

void Window::draw_rect(char c)
{
	for (int x = upper_left.x; x <= lower_right.x; ++x) {
		gotoXY(x, upper_left.y);
		std::cout << c;
		gotoXY(x, lower_right.y);
		std::cout << c;
	}
	for (int y = upper_left.y + 1; y < lower_right.y; ++y) {
		gotoXY(upper_left.x, y);
		std::cout << c;
		gotoXY(lower_right.x, y);
		std::cout << c;
	}
}

void Window::print_center_align(std::string st, int line)
{
	int y = ((lower_right.y + upper_left.y) - st.size()) / 2;
	gotoXY(line, y);
	std::cout << st.c_str();
}

Point::Point()
{
}

Point::Point(int x, int y):x(x), y(y)
{
}

Point Point::operator+(const Point & b)
{
	return Point(x + b.x, y + b.y);
}

void Window::set_pos(Point upper, Point lower) {
	upper_left = upper, lower_right = lower;
}