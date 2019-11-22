#include "lane.h"

Lane::Lane(Point upper, Point lower):Window(upper, lower)
{
}

void Lane::do_tick()
{
}

void Lane::render()
{
	draw_rect('#');
}
