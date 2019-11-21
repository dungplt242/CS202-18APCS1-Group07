#pragma once

struct Point {
	int x, y;
};

class Window {
public:
	Window();
	virtual ~Window();
private:
	Point upper_left, lower_right;
};