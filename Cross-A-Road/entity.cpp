#include "entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::draw()
{
<<<<<<< Updated upstream
=======
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
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < mp[i].size(); ++j) {
			int color;
			fin >> color;
			if (mp[i][j] != ' ') {
				if (isFlipped && 0)
					pixels.push_back({ {i, mxlength - j - 1}, mp[i][j], color });
				else pixels.push_back({ {i, j}, mp[i][j], color });
			}
		}
	}
>>>>>>> Stashed changes
}
