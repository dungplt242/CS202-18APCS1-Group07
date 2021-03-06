#include "entity.h"
#include "console.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include "random.h"

using Console::gotoXY;

Entity::Entity()
{
}

Entity::Entity(Point loca):location(loca)
{
}


Entity::~Entity()
{
}


bool Entity::collide(std::shared_ptr<Entity> other)
{
	for (int i = 0; i < other->pixels.size(); i++)
		for (int j = 0; j < pixels.size(); j++) {
			if (other->pixels[i].x + other->location.x == pixels[j].x + location.x
				&& other->pixels[i].y + other->location.y == pixels[j].y + location.y)
				return true;
		}
	return false;
}

void Entity::load_icon(bool isFlipped)
{
	std::string filepath = "Data/" + type_name() + ".txt";
	int n;
	std::ifstream fin(filepath);
	if (!fin.is_open()) {
		std::cerr << "Can't find file " + type_name() << ".txt\n";
		exit(1);
	}
	fin >> n;
	std::vector<std::string> mp(n);
	fin.ignore(100, '\n');
	int mxlength = 0;
	for (int i = 0; i < n; ++i) {
		std::getline(fin, mp[i]);
		if (mxlength < (int)mp[i].size()) mxlength = (int)mp[i].size();
	}
	auto Flip = [&](char c) {
		switch (c) {
		case '\\': return '/';
		case '/': return '\\';
		case '(': return ')';
		case ')': return '(';
		case '<': return '>';
		case '>': return '<';
		default: return c;
		}

	};
	int col = Random::Int(0, 14);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < mp[i].size(); ++j) {
			int color;
			fin >> color;
			color = col;
			if (mp[i][j] != ' ') {
				if (isFlipped)
					pixels.push_back({ {i, mxlength - j - 1}, Flip(mp[i][j]), color });
				else pixels.push_back({ {i, j}, mp[i][j], color });
			}
		}
	}
}


