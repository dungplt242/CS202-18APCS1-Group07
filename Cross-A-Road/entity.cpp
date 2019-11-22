#include "entity.h"
#include "console.h"
#include <iostream>
#include <string>
#include <fstream>

using Console::gotoXY;

Entity::Entity()
{
}


Entity::~Entity()
{
}


bool Entity::collide(const Entity& other)
{
	return false;
}

void Entity::load_icon()
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
	for (int i = 0; i < n; ++i) {
		std::getline(fin, mp[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < mp[i].size(); ++j) {
			int color;
			fin >> color;
			if (mp[i][j] != ' ') {
				pixels.push_back({ {i, j}, mp[i][j], color });
			}
		}
	}
}
